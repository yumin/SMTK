//=========================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//=========================================================================
// .NAME XmlDocV2Parser.h -
// .SECTION Description
// .SECTION See Also

#ifndef __smtk_io_XmlDocV2Parser_h
#define __smtk_io_XmlDocV2Parser_h
#include "smtk/SMTKCoreExports.h"
#include "smtk/PublicPointerDefs.h"

#include "smtk/io/Logger.h"

#include "smtk/attribute/System.h"

#include "smtk/model/EntityTypeBits.h"

#include <utility>
#include <string>
#include <vector>

namespace pugi {
class xml_document;
class xml_node;
}

namespace smtk
{
  typedef std::pair<smtk::attribute::ValueItemDefinitionPtr, std::string> ItemExpressionDefInfo;
  typedef std::pair<smtk::attribute::RefItemDefinitionPtr, std::string> AttRefDefInfo;
  namespace io
  {
    // Class for recording problems
    class Logger;

    // Helper struct needed for dealing with attribute references
    struct AttRefInfo
    {
      smtk::attribute::RefItemPtr item;
      int pos;
      std::string attName;
    };

    struct ItemExpressionInfo
    {
      smtk::attribute::ValueItemPtr item;
      int pos;
      std::string expName;
    };

    class SMTKCORE_EXPORT XmlDocV2Parser
    {
    public:
      XmlDocV2Parser(smtk::attribute::System &system);
      virtual ~XmlDocV2Parser();
      void process(pugi::xml_document &doc);
      void process(pugi::xml_node &rootNode);
      static void convertStringToXML(std::string &str);
      const smtk::io::Logger &messageLog() const
      {return this->m_logger;}

      void setReportDuplicateDefinitionsAsErrors(bool mode)
      {this->m_reportAsError = mode;}

    protected:
      void processAttributeInformation(pugi::xml_node &root);
      void processViews(pugi::xml_node &root);
      void processModelInfo(pugi::xml_node &root);

      void processDefinition(pugi::xml_node &defNode);
      void processAttribute(pugi::xml_node &attNode);
      void processItem(pugi::xml_node &node,
                       smtk::attribute::ItemPtr item);
      void processItemDef(pugi::xml_node &node,
                          smtk::attribute::ItemDefinitionPtr idef);
      void processRefItem(pugi::xml_node &node,
                                   smtk::attribute::RefItemPtr item);
      void processRefDef(pugi::xml_node &node,
                         smtk::attribute::RefItemDefinitionPtr idef);
      void processDoubleItem(pugi::xml_node &node,
                             smtk::attribute::DoubleItemPtr item);
      void processDoubleDef(pugi::xml_node &node,
                            smtk::attribute::DoubleItemDefinitionPtr idef);
      void processDirectoryItem(pugi::xml_node &node,
                                smtk::attribute::DirectoryItemPtr item);
      void processDirectoryDef(pugi::xml_node &node,
                               smtk::attribute::DirectoryItemDefinitionPtr idef);
      void processFileItem(pugi::xml_node &node,
                           smtk::attribute::FileItemPtr item);
      void processFileDef(pugi::xml_node &node,
                          smtk::attribute::FileItemDefinitionPtr idef);
      void processGroupItem(pugi::xml_node &node,
                             smtk::attribute::GroupItemPtr item);
      void processGroupDef(pugi::xml_node &node,
                           smtk::attribute::GroupItemDefinitionPtr idef);
      void processIntItem(pugi::xml_node &node,
                          smtk::attribute::IntItemPtr item);
      void processIntDef(pugi::xml_node &node,
                         smtk::attribute::IntItemDefinitionPtr idef);
      void processStringItem(pugi::xml_node &node,
                             smtk::attribute::StringItemPtr item);
      void processStringDef(pugi::xml_node &node,
                            smtk::attribute::StringItemDefinitionPtr idef);
      void processModelEntityItem(pugi::xml_node &node,
                             smtk::attribute::ModelEntityItemPtr item);
      void processModelEntityDef(pugi::xml_node &node,
                            smtk::attribute::ModelEntityItemDefinitionPtr idef);
      void processValueItem(pugi::xml_node &node,
                             smtk::attribute::ValueItemPtr item);
      void processValueDef(pugi::xml_node &node,
                           smtk::attribute::ValueItemDefinitionPtr idef);

      void processAttributeView(pugi::xml_node &node,
                                smtk::view::AttributePtr v);

      void processInstancedView(pugi::xml_node &node,
                                smtk::view::InstancedPtr v);

      void processModelEntityView(pugi::xml_node &node,
                                  smtk::view::ModelEntityPtr v);

      void processSimpleExpressionView(pugi::xml_node &node,
                                       smtk::view::SimpleExpressionPtr v);

      void processGroupView(pugi::xml_node &node,
                            smtk::view::GroupPtr v);

      void processBasicView(pugi::xml_node &node,
                            smtk::view::BasePtr v);

      bool getColor(pugi::xml_node &node, double color[3],
                    const std::string &colorName);

      smtk::model::BitFlags decodeModelEntityMask(const std::string &s);
      static int decodeColorInfo(const std::string &s, double *color);
      bool m_reportAsError;
      smtk::attribute::System &m_system;
      std::vector<ItemExpressionDefInfo> m_itemExpressionDefInfo;
      std::vector<AttRefDefInfo> m_attRefDefInfo;
      std::vector<ItemExpressionInfo> m_itemExpressionInfo;
      std::vector<AttRefInfo> m_attRefInfo;
      std::string m_defaultCategory;
      smtk::io::Logger m_logger;
    private:

    };
  }
}


#endif /* __smtk_io_XmlDocV2Parser_h */