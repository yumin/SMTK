//=========================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//=========================================================================
#include "smtk/bridge/polygon/Session.h"

#include "smtk/AutoInit.h"

#include "smtk/model/EntityRef.h"
#include "smtk/model/SessionRef.h"
#include "smtk/model/Model.h"
#include "smtk/model/Group.h"
#include "smtk/model/VolumeUse.h"
#include "smtk/model/FaceUse.h"
#include "smtk/model/EdgeUse.h"
#include "smtk/model/VertexUse.h"
#include "smtk/model/Volume.h"
#include "smtk/model/Face.h"
#include "smtk/model/Edge.h"
#include "smtk/model/Vertex.h"
#include "smtk/model/Manager.h"
#include "smtk/model/Shell.h"
#include "smtk/model/Chain.h"
#include "smtk/model/Loop.h"

#include "smtk/common/UUID.h"

#include "smtk/Options.h"
#include "smtk/AutoInit.h"

#include "smtk/bridge/polygon/internal/Model.h"

#include <string.h> // for strcmp

using smtk::model::EntityRef;
using namespace smtk::common;

namespace smtk {
  namespace bridge {
    namespace polygon {

/// Default constructor.
Session::Session()
{
  this->initializeOperatorSystem(Session::s_operators);
}

/// Virtual destructor. Here because Session overrides virtual methods from Session.
Session::~Session()
{
}

/// The polygon session supports smtk::model::SESSION_EVERYTHING.
smtk::model::SessionInfoBits Session::allSupportedInformation() const
{
  return smtk::model::SESSION_EVERYTHING;
}

smtk::model::SessionInfoBits Session::transcribeInternal(
  const smtk::model::EntityRef& entity,
  smtk::model::SessionInfoBits requestedInfo,
  int depth)
{
  (void)entity;
  (void)requestedInfo;
  (void)depth;
  return smtk::model::SESSION_EVERYTHING;
}

void Session::addStorage(
  const smtk::common::UUID& uid,
  smtk::bridge::polygon::internal::entity::Ptr s)
{
  this->m_storage[uid] = s;
}

bool Session::removeStorage(const smtk::common::UUID& uid)
{
  return this->m_storage.erase(uid) > 0;
}

    } // namespace polygon
  } //namespace bridge
} // namespace smtk

#include "smtk/bridge/polygon/Session_json.h" // For Session_json
smtkImplementsModelingKernel(
  SMTKPOLYGONSESSION_EXPORT,
  polygon,
  Session_json,
  smtk::model::SessionHasNoStaticSetup,
  smtk::bridge::polygon::Session,
  true /* inherit "universal" operators */
);
smtkComponentInitMacro(smtk_polygon_create_model_operator);
