/*
 * Copyright (c) 2025 Freqchip
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/pwm.h>

#define DT_DRV_COMPAT freqchip_freqchip_pwm

static uint8_t freqchip_pwm_api_init = 0;
// 定义一个变量用来保存分频值
static uint32_t freqchip_pwm_div = 499; 	// 24M / (freqchip_pwm_div + 1) = 48K

static int freqchip_pwm_set_cycles(const struct device *dev, uint32_t channel,
			      uint32_t period_cycles, uint32_t pulse_cycles,
			      pwm_flags_t flags)
{
	printf("%s:%s,%d,%d,%d,%x\n", __func__, dev->name, channel, period_cycles, 
		pulse_cycles, flags);

	struct_PWM_Config_t PWM_Config;

	PWM_Config.Period = period_cycles;
	PWM_Config.Negedge = pulse_cycles;
	PWM_Config.Prescale = freqchip_pwm_div;
	PWM_Config.Posedge = 0;
	pwm_config(PWM1, 1<<channel, PWM_Config);
	if (freqchip_pwm_api_init == 0) {
		__SYSTEM_PWM1_CLK_ENABLE();

		freqchip_pwm_api_init = 1;
		GPIO_InitTypeDef gpio_handle;
		gpio_handle.Pin = 1<<channel;
		gpio_handle.Mode = GPIO_MODE_AF_PP;
		gpio_handle.Pull = GPIO_PULLUP;
		gpio_handle.Alternate = GPIO_FUNCTION_4;
		gpio_init(GPIOD, &gpio_handle);

		// PWM_Config.Prescale = 1;
		// PWM_Config.Period = 50;
		// PWM_Config.Posedge = 0;
		// PWM_Config.Negedge = 25;

		pwm_output_enable(PWM1, 1<<channel);
	} else {
		// pwm_config(PWM1, 1<<channel, PWM_Config);
		pwm_output_updata(PWM1, 1<<channel);
	}

	// 这里需要判断这个IO是否可用，我现在默认都是可用的
	if (true) {
		return 0;
	} else {
		return -ENOTSUP;
	}
}

#ifdef CONFIG_PWM_CAPTURE
static int freqchip_pwm_configure_capture(const struct device *dev, uint32_t channel,
				     pwm_flags_t flags,
				     pwm_capture_callback_handler_t cb,
				     void *user_data)
{
	printf("%s:%s\n", __func__, dev->name);
	// 这里需要判断这个IO是否可用，我现在默认都是可用的
	if (true) {
		return 0;
	} else {
		return -ENOTSUP;
	}
}

static int freqchip_pwm_enable_capture(const struct device *dev, uint32_t channel)
{
	printf("%s:%s\n", __func__, dev->name);
	// 这里需要判断这个IO是否可用，我现在默认都是可用的
	if (true) {
		return 0;
	} else {
		return -ENOTSUP;
	}
}

static int freqchip_pwm_disable_capture(const struct device *dev, uint32_t channel)
{
	printf("%s:%s\n", __func__, dev->name);
	// 这里需要判断这个IO是否可用，我现在默认都是可用的
	if (true) {
		return 0;
	} else {
		return -ENOTSUP;
	}
}
#endif /* CONFIG_PWM_CAPTURE */

static int freqchip_pwm_get_cycles_per_sec(const struct device *dev,
				      uint32_t channel, uint64_t *cycles)
{
	printf("%s:%s\n", __func__, dev->name);

	*cycles = 24000000 / (freqchip_pwm_div + 1);

	// 这里需要判断这个IO是否可用，我现在默认都是可用的
	if (true) {
		return 0;
	} else {
		return -ENOTSUP;
	}
}

static DEVICE_API(pwm, freqchip_pwm_api) = {
	.set_cycles = freqchip_pwm_set_cycles,
#ifdef CONFIG_PWM_CAPTURE
	.configure_capture = freqchip_pwm_configure_capture,
	.enable_capture = freqchip_pwm_enable_capture,
	.disable_capture = freqchip_pwm_disable_capture,
#endif /* CONFIG_PWM_CAPTURE */
	.get_cycles_per_sec = freqchip_pwm_get_cycles_per_sec,
};

static int pwm_freqchip_init(const struct device *dev) {
    printf("FreqChip pwm %s Initialized\n", dev->name);
    return 0;
}

#define FREQCHIP_PWM_INIT(n)							       \
	DEVICE_DT_INST_DEFINE(n, pwm_freqchip_init, NULL, NULL, NULL, POST_KERNEL,	       \
			      CONFIG_PWM_INIT_PRIORITY, &freqchip_pwm_api);

DT_INST_FOREACH_STATUS_OKAY(FREQCHIP_PWM_INIT)
