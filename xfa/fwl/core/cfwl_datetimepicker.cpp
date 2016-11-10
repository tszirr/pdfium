// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fwl/core/cfwl_datetimepicker.h"

#include <memory>

#include "third_party/base/ptr_util.h"
#include "xfa/fwl/core/fwl_error.h"
#include "xfa/fwl/core/ifwl_datetimepicker.h"
#include "xfa/fwl/core/ifwl_widget.h"

namespace {

IFWL_DateTimePicker* ToDateTimePicker(IFWL_Widget* widget) {
  return static_cast<IFWL_DateTimePicker*>(widget);
}

}  // namespace

CFWL_DateTimePicker::CFWL_DateTimePicker(const IFWL_App* app)
    : CFWL_Widget(app), m_iYear(2011), m_iMonth(1), m_iDay(1) {}

CFWL_DateTimePicker::~CFWL_DateTimePicker() {}

void CFWL_DateTimePicker::Initialize() {
  ASSERT(!m_pIface);

  m_pIface = pdfium::MakeUnique<IFWL_DateTimePicker>(
      m_pApp, pdfium::MakeUnique<CFWL_WidgetProperties>(this));

  CFWL_Widget::Initialize();
}

FWL_Error CFWL_DateTimePicker::SetToday(int32_t iYear,
                                        int32_t iMonth,
                                        int32_t iDay) {
  m_iYear = iYear;
  m_iMonth = iMonth;
  m_iDay = iDay;
  return FWL_Error::Succeeded;
}

int32_t CFWL_DateTimePicker::CountSelRanges() {
  return ToDateTimePicker(GetWidget())->CountSelRanges();
}

int32_t CFWL_DateTimePicker::GetSelRange(int32_t nIndex, int32_t& nStart) {
  return ToDateTimePicker(GetWidget())->GetSelRange(nIndex, nStart);
}

FWL_Error CFWL_DateTimePicker::GetEditText(CFX_WideString& wsText) {
  return ToDateTimePicker(GetWidget())->GetEditText(wsText);
}

FWL_Error CFWL_DateTimePicker::SetEditText(const CFX_WideString& wsText) {
  return ToDateTimePicker(GetWidget())->SetEditText(wsText);
}

FWL_Error CFWL_DateTimePicker::GetCurSel(int32_t& iYear,
                                         int32_t& iMonth,
                                         int32_t& iDay) {
  return ToDateTimePicker(GetWidget())->GetCurSel(iYear, iMonth, iDay);
}

FWL_Error CFWL_DateTimePicker::SetCurSel(int32_t iYear,
                                         int32_t iMonth,
                                         int32_t iDay) {
  return ToDateTimePicker(GetWidget())->SetCurSel(iYear, iMonth, iDay);
}

FWL_Error CFWL_DateTimePicker::GetCaption(IFWL_Widget* pWidget,
                                          CFX_WideString& wsCaption) {
  wsCaption = m_wsData;
  return FWL_Error::Succeeded;
}

FWL_Error CFWL_DateTimePicker::GetToday(IFWL_Widget* pWidget,
                                        int32_t& iYear,
                                        int32_t& iMonth,
                                        int32_t& iDay) {
  iYear = m_iYear;
  iMonth = m_iMonth;
  iDay = m_iDay;
  return FWL_Error::Succeeded;
}

bool CFWL_DateTimePicker::CanUndo() {
  return ToDateTimePicker(GetWidget())->CanUndo();
}

bool CFWL_DateTimePicker::CanRedo() {
  return ToDateTimePicker(GetWidget())->CanRedo();
}

bool CFWL_DateTimePicker::Undo() {
  return ToDateTimePicker(GetWidget())->Undo();
}

bool CFWL_DateTimePicker::Redo() {
  return ToDateTimePicker(GetWidget())->Redo();
}

bool CFWL_DateTimePicker::CanCopy() {
  return ToDateTimePicker(GetWidget())->CanCopy();
}

bool CFWL_DateTimePicker::CanCut() {
  return ToDateTimePicker(GetWidget())->CanCut();
}

bool CFWL_DateTimePicker::CanSelectAll() {
  return ToDateTimePicker(GetWidget())->CanSelectAll();
}

bool CFWL_DateTimePicker::Copy(CFX_WideString& wsCopy) {
  return ToDateTimePicker(GetWidget())->Copy(wsCopy);
}

bool CFWL_DateTimePicker::Cut(CFX_WideString& wsCut) {
  return ToDateTimePicker(GetWidget())->Copy(wsCut);
}

bool CFWL_DateTimePicker::Paste(const CFX_WideString& wsPaste) {
  return ToDateTimePicker(GetWidget())->Paste(wsPaste);
}

bool CFWL_DateTimePicker::SelectAll() {
  return ToDateTimePicker(GetWidget())->SelectAll();
}

bool CFWL_DateTimePicker::Delete() {
  return ToDateTimePicker(GetWidget())->Delete();
}

bool CFWL_DateTimePicker::DeSelect() {
  return ToDateTimePicker(GetWidget())->DeSelect();
}

FWL_Error CFWL_DateTimePicker::GetBBox(CFX_RectF& rect) {
  return ToDateTimePicker(GetWidget())->GetBBox(rect);
}

FWL_Error CFWL_DateTimePicker::SetEditLimit(int32_t nLimit) {
  return ToDateTimePicker(GetWidget())->SetEditLimit(nLimit);
}

void CFWL_DateTimePicker::ModifyEditStylesEx(uint32_t dwStylesExAdded,
                                             uint32_t dwStylesExRemoved) {
  ToDateTimePicker(GetWidget())
      ->ModifyEditStylesEx(dwStylesExAdded, dwStylesExRemoved);
}
