# SPDX-License-Identifier: (GPL-2.0-only OR BSD-3-Clause)
# This file is provided under a dual BSD/GPLv2 license. When using or
# redistributing this file, you may do so under either license.
#
# Copyright(c) 2021 Advanced Micro Devices, Inc. All rights reserved.

snd-sof-amd-acp-objs := acp.o acp-loader.o acp-ipc.o acp-pcm.o acp-stream.o acp-trace.o acp-common.o
snd-sof-amd-renoir-objs := pci-rn.o renoir.o
snd-sof-amd-rembrandt-objs := pci-rmb.o rembrandt.o
snd-sof-amd-vangogh-objs := pci-vangogh.o vangogh.o

obj-$(CONFIG_SND_SOC_SOF_AMD_COMMON) += snd-sof-amd-acp.o
obj-$(CONFIG_SND_SOC_SOF_AMD_RENOIR) +=snd-sof-amd-renoir.o
obj-$(CONFIG_SND_SOC_SOF_AMD_REMBRANDT) +=snd-sof-amd-rembrandt.o
obj-$(CONFIG_SND_SOC_SOF_AMD_VANGOGH) +=snd-sof-amd-vangogh.o
