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
 * $Id: counter.hxx 627 2020-08-15 14:44:04Z li $
 */

#ifndef _SDTL_STREAM_COUNTER_CC_
#define _SDTL_STREAM_COUNTER_CC_

#include "util.hxx"
#include <iostream>

namespace sdtl {

template<class _T> std::ostream &operator<<(std::ostream &, const counter<_T> &);

////////////////////////////////////////////////////////////////////////////////
//
// Counter operations.
//
////////////////////////////////////////////////////////////////////////////////

/**
 *
 */
template<class _T> std::ostream &operator<<(std::ostream &out, const counter<_T> &c) {
  if (c.size()) {
    out << c(0) << "|" << c[c(0)];
    for (size_t i = 1; i < c.size(); i++) {
      out << " " << c(i) << "|" << c[c(i)];
    }
  }
  return out;
}

}

#endif /* _SDTL_STREAM_COUNTER_CC_ */
