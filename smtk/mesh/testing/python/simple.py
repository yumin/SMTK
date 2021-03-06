#=============================================================================
#
#  Copyright (c) Kitware, Inc.
#  All rights reserved.
#  See LICENSE.txt for details.
#
#  This software is distributed WITHOUT ANY WARRANTY; without even
#  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
#  PURPOSE.  See the above copyright notice for more information.
#
#=============================================================================


import os
import smtk
import smtk.testing
import sys


def test_file_load():
    m = smtk.mesh.Manager.create()

    # Load the mesh file
    print 'data_dir', smtk.testing.DATA_DIR
    mesh_path = os.path.join(smtk.testing.DATA_DIR, 'mesh', 'sixth_hexflatcore.h5m')
    c = smtk.io.ImportMesh.entireFile(mesh_path,m)
    if not c.isValid():
        raise RuntimeError("Failed to read valid mesh")
    print c
    print c.numberOfMeshes()

    #now dump some very basic info about the collection
    print c.meshes( ).size()
    print c.cells().size()
    print c.points().size()

    #now dump some very basic info about all the meshes
    m = c.meshes()
    print 'info on all meshes'
    print len(m.domains())
    print len(m.dirichlets())
    print len(m.neumanns())
    print m.cells().size()
    print m.points().size()


if __name__ == '__main__':
  smtk.testing.process_arguments()
  test_file_load()