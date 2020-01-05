/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef _IPTS_PROTOCOL_COMMANDS_H_
#define _IPTS_PROTOCOL_COMMANDS_H_

#include <linux/build_bug.h>
#include <linux/types.h>

struct ipts_set_mode_cmd {
	u32 sensor_mode;
	u8 reserved[12];
};
static_assert(sizeof(struct ipts_set_mode_cmd) == 16);

struct ipts_set_mem_window_cmd {
	u32 touch_data_buffer_addr_lower[16];
	u32 touch_data_buffer_addr_upper[16];
	u32 workqueue_addr_lower;
	u32 workqueue_addr_upper;
	u32 doorbell_addr_lower;
	u32 doorbell_addr_upper;
	u32 feedback_buffer_addr_lower[16];
	u32 feedback_buffer_addr_upper[16];
	u32 host2me_addr_lower;
	u32 host2me_addr_upper;
	u32 host2me_size;
	u8 reserved1;
	u8 workqueue_item_size;
	u16 workqueue_size;
	u8 reserved[32];
};
static_assert(sizeof(struct ipts_set_mem_window_cmd) == 320);

struct ipts_feedback_cmd {
	u32 buffer;
	u32 transaction;
	u8 reserved[8];
};
static_assert(sizeof(struct ipts_feedback_cmd) == 16);

/*
 * Commands are sent from the host to the ME
 */
struct ipts_command {
	u32 code;
	union {
		struct ipts_set_mode_cmd set_mode;
		struct ipts_set_mem_window_cmd set_mem_window;
		struct ipts_feedback_cmd feedback;
	} data;
};
static_assert(sizeof(struct ipts_command) == 324);

#endif /* _IPTS_PROTOCOL_COMMANDS_H_ */
