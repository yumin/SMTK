#ifndef __smtk_model_PropertyValuePhrase_h
#define __smtk_model_PropertyValuePhrase_h

#include "smtk/model/PropertyListPhrase.h"
#include "smtk/model/BRepModel.h" // For PropertyType enum.

#include <string>
#include <vector>

namespace smtk {
  namespace model {

/**\brief Describe the value of a named property for user presentation.
  *
  */
class SMTKCORE_EXPORT PropertyValuePhrase : public DescriptivePhrase
{
public:
  smtkTypeMacro(PropertyValuePhrase);
  smtkCreateMacro(DescriptivePhrase);
  PropertyValuePhrase();
  Ptr setup(PropertyType propType, const std::string& propName, DescriptivePhrase::Ptr parent);

  virtual std::string title();
  virtual std::string subtitle();

  virtual smtk::util::UUID relatedEntityId() const;
  virtual Cursor relatedEntity() const;
  virtual std::string relatedPropertyName() const;
  virtual PropertyType relatedPropertyType() const;

  static DescriptivePhraseType propertyToPhraseType(PropertyType p);

protected:
  PropertyType m_propertyType;
  std::string m_propertyName;
};

  } // model namespace
} // smtk namespace

#endif // __smtk_model_DescriptivePhrase_h