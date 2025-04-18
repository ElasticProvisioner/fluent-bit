/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  CProfiles
 *  =========
 *  Copyright (C) 2024 The CProfiles Authors
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */


#include <cprofiles/cprofiles.h>

struct cprof_attribute_unit *cprof_attribute_unit_create(struct cprof_profile *profile)
{
    struct cprof_attribute_unit *instance;

    instance = calloc(1, sizeof(struct cprof_attribute_unit));

    if (instance == NULL) {
        return NULL;
    }

    cfl_list_add(&instance->_head, &profile->attribute_units);

    return instance;
}

void cprof_attribute_unit_destroy(struct cprof_attribute_unit *instance)
{
    if (instance != NULL) {
        if (cfl_list_entry_is_orphan(&instance->_head) == CFL_FALSE) {
            cfl_list_del(&instance->_head);
        }

        free(instance);
    }
}
