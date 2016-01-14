/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Laboratory for Percutaneous Surgery (PerkLab)
  Queen's University, Kingston, ON, Canada. All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Csaba Pinter, PerkLab, Queen's University
  and was supported through the Applied Cancer Research Unit program of Cancer Care
  Ontario with funds provided by the Ontario Ministry of Health and Long-Term Care

==============================================================================*/

#ifndef __qMRMLSegmentEditorWidget_h
#define __qMRMLSegmentEditorWidget_h

// MRMLWidgets includes
#include "qMRMLWidget.h"

#include "qSlicerSegmentationsModuleWidgetsExport.h"

// CTK includes
#include <ctkPimpl.h>

class vtkMRMLNode;
class vtkPolyData;
class vtkObject;
class qMRMLSegmentEditorWidgetPrivate;
class QItemSelection;

/// \brief Qt widget for editing a segment from a segmentation using Editor effects.
/// \ingroup SlicerRt_QtModules_Segmentations_Widgets
class Q_SLICER_MODULE_SEGMENTATIONS_WIDGETS_EXPORT qMRMLSegmentEditorWidget : public qMRMLWidget
{
  Q_OBJECT

public:
  /// Constructor
  explicit qMRMLSegmentEditorWidget(QWidget* parent = 0);
  /// Destructor
  virtual ~qMRMLSegmentEditorWidget();

  /// Get currently selected segmentation MRML node
  Q_INVOKABLE vtkMRMLNode* segmentationNode();
  /// Get currently selected Segmentationsegmentation node's ID
  Q_INVOKABLE QString segmentationNodeID();

  /// Get segment ID of selected segment
  Q_INVOKABLE QString currentSegmentID();

public slots:
  /// Set the MRML \a scene associated with the widget
  virtual void setMRMLScene(vtkMRMLScene* newScene);

  /// Set segmentation MRML node
  Q_INVOKABLE void setSegmentationNode(vtkMRMLNode* node);
  /// Set segmentation MRML node by its ID
  Q_INVOKABLE void setSegmentationNodeID(const QString& nodeID);

protected slots:
  /// Handles changing of current segmentation MRML node
  Q_INVOKABLE void onSegmentationNodeChanged(vtkMRMLNode* node);
  /// Handles changing of the current master volume MRML node
  void onReferenceVolumeNodeChanged(vtkMRMLNode* node);
  /// Handles segment selection changes
  void segmentSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

  /// Activate paint effect
  void activatePaint();

protected:
  /// Create observations between slice view interactor and the widget.
  /// The captured events are propagated to the active effect if any.
  void setupSliceObservations();
  
  /// Callback function invoked when interaction happens
  static void processInteractionEvents(vtkObject* caller, unsigned long eid, void* clientData, void* callData);

protected:
  QScopedPointer<qMRMLSegmentEditorWidgetPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(qMRMLSegmentEditorWidget);
  Q_DISABLE_COPY(qMRMLSegmentEditorWidget);
};

#endif