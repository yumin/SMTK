//=========================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//=========================================================================
// .NAME StringItemDefinition.h -
// .SECTION Description
// .SECTION See Also

#ifndef __smtk_attribute_StringItemDefinition_h
#define __smtk_attribute_StringItemDefinition_h

#include "smtk/attribute/ValueItemDefinitionTemplate.h"

namespace smtk
{
  namespace attribute
  {
    class SMTKCORE_EXPORT StringItemDefinition :
      public ValueItemDefinitionTemplate<std::string>
    {
    public:
      smtkTypeMacro(StringItemDefinition);
      static smtk::attribute::StringItemDefinitionPtr New(const std::string &myName)
      { return smtk::attribute::StringItemDefinitionPtr(new StringItemDefinition(myName));}

      virtual ~StringItemDefinition();
      virtual Item::Type type() const;
      virtual smtk::attribute::ItemPtr buildItem(Attribute *owningAttribute,
                                                int itemPosition) const;
      virtual smtk::attribute::ItemPtr buildItem(Item *owningItem,
                                                int position,
                                                int subGroupPosition) const;
      bool isMultiline() const
      { return this->m_multiline;}
      void setIsMultiline(bool val)
      {this->m_multiline = val;}

      virtual smtk::attribute::ItemDefinitionPtr
        createCopy(smtk::attribute::ItemDefinition::CopyInfo& info) const;
    protected:
      StringItemDefinition(const std::string &myName);
      bool m_multiline;
    private:

    };
  }
}

#endif /* __smtk_attribute_StringItemDefinition_h */
