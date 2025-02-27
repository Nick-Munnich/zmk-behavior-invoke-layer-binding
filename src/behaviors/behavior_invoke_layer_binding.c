#define DT_DRV_COMPAT zmk_behavior_invoke_layer_binding

#include <zephyr/device.h>
#include <drivers/behavior.h>
#include <zephyr/logging/log.h>

#include <zmk/behavior.h>
#include <zmk/keymap.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#if DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT)

static int behavior_invoke_layer_binding_init(const struct device *dev) { return 0; };

static int on_keymap_binding_pressed(struct zmk_behavior_binding *binding, struct zmk_behavior_binding_event event) {
    return zmk_behavior_invoke_binding(zmk_keymap_get_layer_binding_at_idx(binding->param1, binding->param2), event, true);
}

static int on_keymap_binding_released(struct zmk_behavior_binding *binding,
                                      struct zmk_behavior_binding_event event) {
    return zmk_behavior_invoke_binding(zmk_keymap_get_layer_binding_at_idx(binding->param1, binding->param2), event, false);
}

static const struct behavior_driver_api behavior_invoke_layer_binding_driver_api = {
    .binding_pressed = on_keymap_binding_pressed,
    .binding_released = on_keymap_binding_released,
};

BEHAVIOR_DT_INST_DEFINE(0, behavior_invoke_layer_binding_init, NULL, NULL, NULL, POST_KERNEL,
                        CONFIG_KERNEL_INIT_PRIORITY_DEFAULT, &behavior_invoke_layer_binding_driver_api);

#endif /* DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT) */