/*
 * Copyright (c) 2016, Intel Corporation
 * All rights reserved.
 *
 * Author: Jérémy Compostella <jeremy.compostella@intel.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer
 *      in the documentation and/or other materials provided with the
 *      distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _EFIVAR_H_
#define _EFIVAR_H_

#include <efi.h>
#include <efiapi.h>

typedef struct efivar {
	struct efivar *next;
	CHAR16 *name;
	EFI_GUID guid;
	UINT32 attributes;
	void *data;
	UINTN size;
} efivar_t;

efivar_t *efivar_new(CHAR16 *name, EFI_GUID *guid, UINT32 attr,
		     UINTN size, VOID *data);
void efivar_add(efivar_t *var);

efivar_t *efivar_get(const CHAR16 *name, EFI_GUID *guid, efivar_t **prev_p);
efivar_t *efivar_get_first(void);
EFI_STATUS efivar_update(efivar_t *var, UINTN size, VOID *data);

EFI_STATUS efivar_del(efivar_t *var, efivar_t *prev);

void efivar_free(efivar_t *var);
void efivar_free_all(void);

#endif	/* _EFIVAR_H_ */