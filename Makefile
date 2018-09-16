NAME        ?= Ti-FX
COMPRESSED  ?= NO
ICON        ?= iconc.png
DESCRIPTION ?= "Ti-FX graphics library"

SRCDIR := tifx
TESTSDIR := tests

# Note: for patched .makefile
X_INCLUDE += include

include $(CEDEV)/include/.makefile

check:
	@$(CD) $(MAKEDIR)
	@make --silent && echo ">>> Tests successful <<<" || (echo ">>> Tests failed to compile! <<<"; exit 0)

distclean:
	@$(RMDIR) $(call NATIVEPATH,$(OBJDIR))
	@$(RMDIR) $(call NATIVEPATH,$(BINDIR))
	@echo Cleaned build files.

.PHONY: all check clean distclean version gfx dirs