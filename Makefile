PROXY = all clean run
SUBPROJECTS = shunting-yard

.PHONY: $(PROXY) $(SUBPROJECTS)

$(PROXY) $(SUBPROJECTS):
# NOTE: как распараллелить?
	@$(foreach d, $(SUBPROJECTS), $(MAKE) $@ -C $d &&) true
