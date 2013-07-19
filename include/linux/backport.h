/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#ifndef BACKPORT_H
#define BACKPORT_H

#include <linux/input.h>
#include <linux/version.h>

#ifndef UINPUT_MINOR
#define UINPUT_MINOR		223
#endif /* UINPUT_MINOR */

#ifndef COMPAT_USE_64BIT_TIME
#define COMPAT_USE_64BIT_TIME 0
#endif /* COMPAT_USE_64BIT_TIME */

#ifndef INPUT_GENERATE_ABS_ACCESSORS
static inline int input_abs_get_val(struct input_dev *dev,
					  unsigned int axis)
{
	return dev->abs[axis];
}

static inline void input_abs_set_val(struct input_dev *dev,
					   unsigned int axis, int val)
{
	dev->abs[axis] = val;
}

#define INPUT_GENERATE_ABS_ACCESSORS(_suffix, _item)			\
static inline int input_abs_get_##_suffix(struct input_dev *dev,	\
					  unsigned int axis)		\
{									\
	return dev->abs##_suffix[axis];					\
}									\
									\
static inline void input_abs_set_##_suffix(struct input_dev *dev,	\
					   unsigned int axis, int val)	\
{									\
	dev->abs##_suffix[axis] = val;				\
}

INPUT_GENERATE_ABS_ACCESSORS(min, minimum)
INPUT_GENERATE_ABS_ACCESSORS(max, maximum)
INPUT_GENERATE_ABS_ACCESSORS(fuzz, fuzz)
INPUT_GENERATE_ABS_ACCESSORS(flat, flat)
INPUT_GENERATE_ABS_ACCESSORS(res, resolution)
#endif

#endif /* BACKPORT_H */
