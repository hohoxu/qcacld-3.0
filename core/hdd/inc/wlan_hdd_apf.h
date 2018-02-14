/*
 * Copyright (c) 2012-2018 The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * This file was originally distributed by Qualcomm Atheros, Inc.
 * under proprietary terms before Copyright ownership was assigned
 * to the Linux Foundation.
 */

/**
 * DOC: wlan_hdd_apf.h
 *
 * Android Packet Filter related API's and definitions
 */

#ifndef __WLAN_HDD_APF_H
#define __WLAN_HDD_APF_H

#include "sir_api.h"
#include "wlan_hdd_main.h"

/**
 * hdd_get_bpf_offload_cb() - Callback function to BPF Offload
 * @hdd_context: hdd_context
 * @bpf_get_offload: struct for get offload
 *
 * This function receives the response/data from the lower layer and
 * checks to see if the thread is still waiting then post the results to
 * upper layer, if the request has timed out then ignore.
 *
 * Return: None
 */
void hdd_get_bpf_offload_cb(void *hdd_context,
			    struct sir_bpf_get_offload *data);

/**
 * hdd_init_bpf_completion() - Initialize the completion event for bpf
 *
 * Return: None
 */
void hdd_init_bpf_completion(void);

/**
 * wlan_hdd_cfg80211_bpf_offload() - SSR Wrapper to BPF Offload
 * @wiphy:    wiphy structure pointer
 * @wdev:     Wireless device structure pointer
 * @data:     Pointer to the data received
 * @data_len: Length of @data
 *
 * Return: 0 on success; errno on failure
 */

int wlan_hdd_cfg80211_bpf_offload(struct wiphy *wiphy,
				  struct wireless_dev *wdev,
				  const void *data, int data_len);
#endif /* WLAN_HDD_APF_H */
