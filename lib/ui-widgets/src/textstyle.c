﻿/*
 * lib/ui-widgets/src/textstyle.c
 *
 * Copyright (c) 2023, Liu Chao <i@lc-soft.io> All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * This file is part of LCUI, distributed under the MIT License found in the
 * LICENSE.TXT file in the root directory of this source tree.
 */

#include "textstyle.h"

void convert_font_style_to_text_style(ui_text_style_t *fs, pd_text_style_t *ts)
{
	size_t len;
	ts->font_ids = NULL;
	ts->has_style = TRUE;
	ts->has_weight = TRUE;
	ts->has_family = FALSE;
	ts->has_back_color = FALSE;
	ts->has_pixel_size = TRUE;
	ts->has_fore_color = TRUE;
	ts->fore_color = fs->color;
	ts->pixel_size = fs->font_size;
	ts->weight = fs->font_weight;
	ts->style = fs->font_style;
	if (fs->font_ids) {
		for (len = 0; fs->font_ids[len]; ++len)
			;
		ts->font_ids = malloc(sizeof(int) * ++len);
		memcpy(ts->font_ids, fs->font_ids, len * sizeof(int));
		ts->has_family = TRUE;
	}
}