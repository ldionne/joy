EDITABLE_FILES = `find include/ -name *.[h,c]`
COG = tools/cog/scripts/cog.py
MACROIZE = tools/macroize/macroize.py

.PHONY: before_edit after_edit

before_edit:
	python3 ${COG} -x -r ${EDITABLE_FILES}
	python3 ${MACROIZE} ${EDITABLE_FILES} -u

after_edit:
	python3 ${MACROIZE} ${EDITABLE_FILES}
	python3 ${COG} -r ${EDITABLE_FILES}
