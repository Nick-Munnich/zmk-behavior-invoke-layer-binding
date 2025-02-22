if ((NOT CONFIG_ZMK_SPLIT) OR CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
  target_sources_ifdef(CONFIG_ZMK_BEHAVIOR_INVOKE_LAYER_BINDING app PRIVATE src/behaviors/behavior_invoke_layer_binding.c)
endif()