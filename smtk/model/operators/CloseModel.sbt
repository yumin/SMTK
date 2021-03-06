<?xml version="1.0" encoding="utf-8" ?>
<!-- Description of the model "CloseModel" Operator -->
<SMTK_AttributeSystem Version="2">
  <Definitions>
    <!-- Operator -->
    <AttDef Type="close model" BaseType="operator">
      <ItemDefinitions>
        <ModelEntity Name="model" NumberOfRequiredValues="0" Extensible="true">
          <MembershipMask>model</MembershipMask>
        </ModelEntity>
      </ItemDefinitions>
    </AttDef>

    <!-- Result -->
    <AttDef Type="result(close model)" BaseType="result">
      <!-- The close models are stored in the base result's "expunged" item. -->
    </AttDef>
  </Definitions>
</SMTK_AttributeSystem>
