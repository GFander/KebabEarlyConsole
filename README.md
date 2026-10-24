# KebabEarlyConsole

Early **framebuffer console** for the **OnePlus 8T (kebab, SM8250)**, used before
any real display driver exists.

`start.s` maps the splash framebuffer as Normal-NC, and `kebab_early_mark()`
draws a stage marker plus text straight into it. Once the final kernel tables
replace the bootstrap ones, `arm_vm_init()` installs a reserved-VA alias so the
console keeps working through panics.

| Item | Value |
| --- | --- |
| Module type | `driver` (`drivers/KebabEarlyConsole`) |
| Framebuffer | `0x9C000000`, 1080x2400, 4320 bytes per row, BGRA |
| Font | `iso_font` (already in XNU) |

## Why it exists

This phone exposes no UART, so without this console the kernel is silent from
the first instruction until the display driver loads — which never happens
during bring-up. The reference port used `0xB8000000`; kebab's Mu GOP hands the
framebuffer over at `0x9C000000`, and using the wrong address either draws
nothing or faults on unmapped memory.

## Usage

```c
#include <arm64/kebab_early.h>

kebab_early_mark(1, "arm_init entered (MMU on)");
kebab_early_putc('x');
```
