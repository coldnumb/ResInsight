/////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) 2011-     Statoil ASA
//  Copyright (C) 2013-     Ceetron Solutions AS
//  Copyright (C) 2011-2012 Ceetron AS
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

#include "cafPdmChildArrayField.h"
#include "cafPdmField.h"
#include "cafPdmObject.h"

#include "cvfBase.h"
#include "cvfObject.h"

class RimEclipseStatisticsCase;
class RimIdenticalGridCaseGroup;


//==================================================================================================
//
// 
//
//==================================================================================================
class RimEclipseStatisticsCaseCollection : public caf::PdmObject
{
    CAF_PDM_HEADER_INIT;

public:
    RimEclipseStatisticsCaseCollection();
    virtual ~RimEclipseStatisticsCaseCollection();

    caf::PdmChildArrayField<RimEclipseStatisticsCase*> cases;

    RimIdenticalGridCaseGroup* parentCaseGroup();

};