# Find PythonQtGenerator
#
# Sets PYTHONQTGENERATOR_FOUND, PYTHONQTGENERATOR_EXECUTABLE
#


FIND_PROGRAM(PYTHONQTGENERATOR_EXECUTABLE PythonQtGenerator DOC "PythonQt Generator.")
MARK_AS_ADVANCED(PYTHONQTGENERATOR_EXECUTABLE)

SET(PYTHONQTGENERATOR_FOUND 0)
IF(EXISTS PYTHONQTGENERATOR_EXECUTABLE)
  SET(PYTHONQTGENERATOR_FOUND 1)
ENDIF()
