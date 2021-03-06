/*
 * (c) 2020 Copyright, Real-Time Innovations, Inc. (RTI)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "c_cmn_win.h" /* for PCCERT_CONTEXT */
#include "c_cmn_ossl.h" /* for RSA */

RSA *
ncrypt_rsa_new(PCCERT_CONTEXT cert_ctx);

void
ncrypt_rsa_free(RSA *rsa_key);

/* Additional sign and verify methods to support PSS (for local use only) */
int
ncrypt_rsa_pss_sign_digest(int md_type, const unsigned char *dgst,
                           unsigned int dgstlen, unsigned char *sig,
                           unsigned int *siglen, const RSA *rsa_key,
                           const EVP_MD *pss_md_mgf1, unsigned int pss_saltlen);
