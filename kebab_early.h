/* Screen diagnostics through bootstrap TTBR0 and the final kernel TTBR1. */
#ifndef _ARM64_KEBAB_EARLY_H_
#define _ARM64_KEBAB_EARLY_H_

#include <pexpert/arm64/board_config.h>
#include <stdarg.h>
#include <stdint.h>

#if defined(KEBAB)
void kebab_early_mark(unsigned int stage, const char *label);
void kebab_early_putc(char c);
void kebab_early_panic(const char *fmt, va_list *args);
void kebab_early_relocate(uint64_t base);
void kebab_early_disable(void);
#else
static inline void kebab_early_mark(unsigned int stage, const char *label)
{
	(void)stage;
	(void)label;
}
static inline void kebab_early_disable(void) {}
#endif

#endif
