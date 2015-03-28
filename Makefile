PROXY = all clean run
SUBPROJECTS = $(shell find -type d -not -path './.*' -not -name '.')

.PHONY: $(PROXY) $(SUBPROJECTS)

$(PROXY) $(SUBPROJECTS):
#NOTE: как распараллелить?
	@$(foreach d, $(SUBPROJECTS), $(MAKE) $@ -C $d &&) true
