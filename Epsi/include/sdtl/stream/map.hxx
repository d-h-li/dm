/*-
 * Copyright (c) 2007-2012 Dominique Li <dominique.li@univ-tours.fr>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Id: map.hxx 627 2020-08-15 14:44:04Z li $
 */

#ifndef _SDTL_STREAM_MAP_CC_
#define _SDTL_STREAM_MAP_CC_

#include "util.hxx"
#include <iostream>

namespace sdtl {

template<class _K, class _V> std::ostream &operator<<(std::ostream &, const map<_K, _V> &);

template<class _K, class _V> std::istream &operator>>(std::istream &, map<_K, _V> &);

////////////////////////////////////////////////////////////////////////////////
//
// Map operations.
//
////////////////////////////////////////////////////////////////////////////////

/**
 *
 */
template<class _K, class _V> std::ostream &operator<<(std::ostream &out, const map<_K, _V> &m) {
  for (size_t i = 0; i < m.size(); i++) {
    out << m.key(i) << '\t' << m.value(i) << std::endl;
  }
  return out;
}

/**
 *
 */
template<class _K, class _V> std::istream &operator>>(std::istream &in, map<_K, _V> &m) {
  m.clear();
  _K k;
  _V v;
  while (in >> k) {
    if (in >> v) {
      m.set(k, v);
    } else {
      throw format_error();
    }
  }
  return in;
}

}

#endif /* _SDTL_STREAM_MAP_CC_ */
