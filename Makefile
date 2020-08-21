.PHONY: clean All

All:
	@echo "----------Building project:[ RosePattern - Release ]----------"
	@cd "RosePattern" && "$(MAKE)" -f  "RosePattern.mk"
clean:
	@echo "----------Cleaning project:[ RosePattern - Release ]----------"
	@cd "RosePattern" && "$(MAKE)" -f  "RosePattern.mk" clean
