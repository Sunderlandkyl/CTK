/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

#ifndef __ctkVTKLookupTable_h
#define __ctkVTKLookupTable_h

// CTK includes
#include "ctkTransferFunction.h"
#include "ctkPimpl.h"
#include "ctkVisualizationVTKWidgetsExport.h"
#include "ctkVTKObject.h"

class vtkLookupTable;
class ctkVTKLookupTablePrivate;

/// \ingroup Visualization_VTK_Widgets
///
/// Transfer function for a vtkColorTransferFunction. 
/// The value is an RGB QColor (no alpha supported)
class CTK_VISUALIZATION_VTK_WIDGETS_EXPORT ctkVTKLookupTable: public ctkTransferFunction
{
  Q_OBJECT;
  QVTK_OBJECT;
public:
  ctkVTKLookupTable(QObject* parent = 0);
  ctkVTKLookupTable(vtkLookupTable* lookupTable, QObject* parent = 0);
  virtual ~ctkVTKLookupTable();
  
  Q_INVOKABLE virtual ctkControlPoint* controlPoint(int index)const;
  Q_INVOKABLE virtual QVariant value(qreal pos)const;
  Q_INVOKABLE virtual int count()const;
  Q_INVOKABLE virtual bool isDiscrete()const;
  Q_INVOKABLE virtual bool isEditable()const;

  Q_INVOKABLE virtual void range(qreal& minRange, qreal& maxRange)const;
  Q_INVOKABLE virtual QVariant minValue()const;
  Q_INVOKABLE virtual QVariant maxValue()const;

  Q_INVOKABLE virtual int insertControlPoint(const ctkControlPoint& cp);
  Q_INVOKABLE virtual int insertControlPoint(qreal pos);

  Q_INVOKABLE virtual void setControlPointPos(int index, qreal pos);
  Q_INVOKABLE virtual void setControlPointValue(int index, const QVariant& value);

  Q_INVOKABLE virtual void removeControlPoint( qreal pos );

  Q_INVOKABLE void setLookupTable(vtkLookupTable* lookupTable);
  vtkLookupTable* lookupTable()const;
protected:
  qreal indexToPos(int index)const;
  int posToIndex(qreal pos)const;
protected:
  QScopedPointer<ctkVTKLookupTablePrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(ctkVTKLookupTable);
  Q_DISABLE_COPY(ctkVTKLookupTable);
};

#endif
