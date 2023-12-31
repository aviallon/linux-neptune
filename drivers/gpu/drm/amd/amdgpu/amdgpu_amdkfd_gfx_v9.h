/*
 * Copyright 2019 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */



void kgd_gfx_v9_program_sh_mem_settings(struct amdgpu_device *adev, uint32_t vmid,
		uint32_t sh_mem_config,
		uint32_t sh_mem_ape1_base, uint32_t sh_mem_ape1_limit,
		uint32_t sh_mem_bases, uint32_t inst);
int kgd_gfx_v9_set_pasid_vmid_mapping(struct amdgpu_device *adev, u32 pasid,
		unsigned int vmid, uint32_t inst);
int kgd_gfx_v9_init_interrupts(struct amdgpu_device *adev, uint32_t pipe_id,
				uint32_t inst);
int kgd_gfx_v9_hqd_load(struct amdgpu_device *adev, void *mqd, uint32_t pipe_id,
			uint32_t queue_id, uint32_t __user *wptr,
			uint32_t wptr_shift, uint32_t wptr_mask,
			struct mm_struct *mm, uint32_t inst);
int kgd_gfx_v9_hiq_mqd_load(struct amdgpu_device *adev, void *mqd,
			    uint32_t pipe_id, uint32_t queue_id,
			    uint32_t doorbell_off, uint32_t inst);
int kgd_gfx_v9_hqd_dump(struct amdgpu_device *adev,
			uint32_t pipe_id, uint32_t queue_id,
			uint32_t (**dump)[2], uint32_t *n_regs, uint32_t inst);
bool kgd_gfx_v9_hqd_is_occupied(struct amdgpu_device *adev,
			uint64_t queue_address, uint32_t pipe_id,
			uint32_t queue_id, uint32_t inst);
int kgd_gfx_v9_hqd_destroy(struct amdgpu_device *adev, void *mqd,
				enum kfd_preempt_type reset_type,
				unsigned int utimeout, uint32_t pipe_id,
				uint32_t queue_id, uint32_t inst);
int kgd_gfx_v9_wave_control_execute(struct amdgpu_device *adev,
					uint32_t gfx_index_val,
					uint32_t sq_cmd, uint32_t inst);
bool kgd_gfx_v9_get_atc_vmid_pasid_mapping_info(struct amdgpu_device *adev,
					uint8_t vmid, uint16_t *p_pasid);
void kgd_gfx_v9_set_vm_context_page_table_base(struct amdgpu_device *adev,
			uint32_t vmid, uint64_t page_table_base);
void kgd_gfx_v9_get_cu_occupancy(struct amdgpu_device *adev, int pasid,
		int *pasid_wave_cnt, int *max_waves_per_cu, uint32_t inst);
void kgd_gfx_v9_program_trap_handler_settings(struct amdgpu_device *adev,
		uint32_t vmid, uint64_t tba_addr, uint64_t tma_addr,
		uint32_t inst);
void kgd_gfx_v9_acquire_queue(struct amdgpu_device *adev, uint32_t pipe_id,
				uint32_t queue_id, uint32_t inst);
uint64_t kgd_gfx_v9_get_queue_mask(struct amdgpu_device *adev,
				uint32_t pipe_id, uint32_t queue_id);
void kgd_gfx_v9_release_queue(struct amdgpu_device *adev, uint32_t inst);
