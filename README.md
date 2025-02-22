# ZMK-INVOKE-LAYER-BINDING

This module adds a `&layer x y` behavior. Pass a layer number as x and a key position as y, and the behavior will invoke the behavior at that position. Untested.

To use it, include the module as described in the ZMK docs, then include the behavior:

```c
#include <behaviors/invoke_layer_binding.dtsi>
```
