<?xml version="1.0" encoding="utf-8" ?>
<!-- Description of the CGM "CreatePrism" Operator -->
<SMTK_AttributeSystem Version="2">
  <Definitions>
    <!-- Operator -->
    <AttDef Type="create prism" BaseType="operator">
      <ItemDefinitions>
        <Double Name="height" NumberOfRequiredValues="1">
          <DefaultValue>1.0</DefaultValue>
        </Double>
        <Double Name="major radius" NumberOfRequiredValues="1">
          <DefaultValue>1.0</DefaultValue>
        </Double>
        <Double Name="minor radius" NumberOfRequiredValues="1">
          <DefaultValue>1.0</DefaultValue>
        </Double>
        <Int Name="number of sides" NumberOfRequiredValues="1">
          <Min Inclusive="true">3</Min>
          <DefaultValue>3</DefaultValue>
        </Int>
      </ItemDefinitions>
    </AttDef>
    <!-- Result -->
    <AttDef Type="result(create prism)" BaseType="result">
      <ItemDefinitions>
        <!-- The prism created. -->
        <ModelEntity Name="bodies" NumberOfRequiredValues="1" Extensible="1" MembershipMask="4096"/>
      </ItemDefinitions>
    </AttDef>
  </Definitions>
</SMTK_AttributeSystem>
