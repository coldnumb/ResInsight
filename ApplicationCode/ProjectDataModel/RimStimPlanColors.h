/////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) 2017 -     Statoil ASA
// 
//  ResInsight is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
// 
//  ResInsight is distributed in the hope that it will be useful, but WITHOUT ANY
//  WARRANTY; without even the implied warranty of MERCHANTABILITY or
//  FITNESS FOR A PARTICULAR PURPOSE.
// 
//  See the GNU General Public License at <http://www.gnu.org/licenses/gpl.html> 
//  for more details.
//
/////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "RimCheckableNamedObject.h"

#include "cafAppEnum.h"
#include "cafPdmChildField.h"
#include "cafPdmField.h"
#include "cafPdmChildArrayField.h"

// Include to make Pdm work for cvf::Color
#include "cafPdmFieldCvfColor.h"

namespace caf {
    class PdmOptionItemInfo;
}


class RimLegendConfig;
class RimFractureTemplateCollection;

//==================================================================================================
///  
///  
//==================================================================================================
class RimStimPlanColors : public RimCheckableNamedObject
{
    CAF_PDM_HEADER_INIT;

public:
    RimStimPlanColors();
    virtual ~RimStimPlanColors();

    RimLegendConfig*    activeLegend() const;
    QString             resultName() const;
    QString             unit() const;
    float               opacityLevel() const;
    cvf::Color3f        defaultColor() const;

    void                loadDataAndUpdate();
    void                updateLegendData();

protected:
    virtual QList<caf::PdmOptionItemInfo>   calculateValueOptions(const caf::PdmFieldHandle* fieldNeedingOptions, bool* useOptionsOnly) override;
    virtual void                            fieldChangedByUi(const caf::PdmFieldHandle* changedField, const QVariant& oldValue, const QVariant& newValue) override;
    virtual void                            defineUiTreeOrdering(caf::PdmUiTreeOrdering& uiTreeOrdering, QString uiConfigName = "") override;
    virtual void                            defineUiOrdering(QString uiConfigName, caf::PdmUiOrdering& uiOrdering) override;
    virtual void                            defineEditorAttribute(const caf::PdmFieldHandle* field, QString uiConfigName, caf::PdmUiEditorAttribute* attribute) override;

private:
    RimFractureTemplateCollection*          fractureTemplateCollection() const;
    static QString                          toString(const std::pair<QString, QString>& resultNameAndUnit);
    
    static QString                          toResultName(const QString& resultNameAndUnit);
    static QString                          toUnit(const QString& resultNameAndUnit);

private:
    caf::PdmField<float>                        m_opacityLevel;
    caf::PdmField<cvf::Color3f>                 m_defaultColor;
    caf::PdmField<QString>                      m_resultNameAndUnit;
    caf::PdmChildArrayField<RimLegendConfig*>   m_legendConfigurations;
};

