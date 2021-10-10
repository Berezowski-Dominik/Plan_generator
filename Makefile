.PHONY: clean All

All:
	@echo "----------Building project:[ Plan - Debug ]----------"
	@cd "Plan" && "$(MAKE)" -f  "Plan.mk"
clean:
	@echo "----------Cleaning project:[ Plan - Debug ]----------"
	@cd "Plan" && "$(MAKE)" -f  "Plan.mk" clean
