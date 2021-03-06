TEMPLATE	= app
LANGUAGE	= C++

CONFIG	+= qt warn_on release

LIBS	+= -lQVTK -L/usr/lib/vtk -lvtkCommon -lvtkFiltering -lvtkGraphics -lvtkHybrid -lvtkImaging -lvtkIO -lvtkRendering -lvtkftgl -L/usr/lib/graphviz -lgvc -lgraph -L${HOME}/MOAB/lib -lMOAB -lnetcdf_c++ -lnetcdf -lhdf5

INCLUDEPATH	+= /home/tautges/MOAB /usr/include/vtk/Common /usr/include/vtk/Rendering /usr/include/vtk/Graphics /usr/include/vtk /home/tautges/vtkSNL /home/tautges/vtkSNL/IO /usr/include/vtk/Filtering /usr/include/graphviz

SOURCES	+= main.cpp \
	CropTool.cpp \
	DrawDual.cpp \
        vtkMOABReader.cxx \
        vtkMOABUtils.cxx

FORMS	= uiQVDual.ui \
	CropToolpopup.ui \
	SheetDiagramPopup.ui

unix {
  CONFIG += warn_on opengl qt debug
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}












































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































CONFIG	+= qt warn_on release



