#include "smtk/model/ImportJSON.h"
#include "smtk/model/Storage.h"
#include "smtk/vtk/vtkSMTKModelMultiBlockSource.h"

#include "vtkActor.h"
#include "vtkCommand.h"
#include "vtkCompositePolyDataMapper.h"
#include "vtkDataSetAttributes.h"
#include "vtkInteractorStyleSwitch.h"
#include "vtkNew.h"
#include "vtkPolyData.h"
#include "vtkPolyDataMapper.h"
#include "vtkPolyDataWriter.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkSmartPointer.h"
#include "vtkStringArray.h"

using namespace smtk::model;
using namespace smtk::util;

int main(int argc, char* argv[])
{
  int debug = argc > 2 ? 1 : 0;
  std::ifstream file(argc > 1 ? argv[1] : "smtkModel.json");
  if (!file.good())
    {
    cout
      << "Could not open file \"" << (argc > 1 ? argv[1] : "smtkModel.json") << "\".\n\n"
      << "Usage:\n  " << argv[0] << " [[filename] debug]\n"
      << "where\n"
      << "  filename is the path to a JSON model.\n"
      << "  debug    is any character; its presence turns the test into an interactive demo.\n\n"
      ;
    return 1;
    }
  if (debug)
    {
    cout
      << "\n\n"
      << "Press 'q' to exit\n\n"
      ;
    }
  std::string data(
    (std::istreambuf_iterator<char>(file)),
    (std::istreambuf_iterator<char>()));

  UUIDsToEntities smTopology;
  UUIDsToArrangements smArrangements;
  UUIDsToTessellations smTessellation;
  StoragePtr sm = StoragePtr(new Storage(&smTopology, &smArrangements, &smTessellation));

  int status = ! ImportJSON::intoModel(data.c_str(), sm.get());
  if (! status)
    {
    vtkNew<vtkActor> act;
    vtkNew<vtkSMTKModelMultiBlockSource> src;
    vtkNew<vtkCompositePolyDataMapper> map;
    vtkNew<vtkRenderer> ren;
    vtkNew<vtkRenderWindow> win;
    src->SetModel(sm);
    map->SetInputConnection(src->GetOutputPort());
    act->SetMapper(map.GetPointer());

    win->AddRenderer(ren.GetPointer());
    ren->AddActor(act.GetPointer());

    vtkRenderWindowInteractor* iac = win->MakeRenderWindowInteractor();
    vtkInteractorStyleSwitch::SafeDownCast(iac->GetInteractorStyle())->SetCurrentStyleToTrackballCamera();
    win->SetInteractor(iac);

    win->Render();
    ren->ResetCamera();

    if (debug)
      {
      iac->Start();
      }
    }

  return status;
}