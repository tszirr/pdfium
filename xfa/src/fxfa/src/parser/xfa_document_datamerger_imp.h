// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef XFA_SRC_FXFA_SRC_PARSER_XFA_DOCUMENT_DATAMERGER_IMP_H_
#define XFA_SRC_FXFA_SRC_PARSER_XFA_DOCUMENT_DATAMERGER_IMP_H_

#include "xfa/src/fxfa/src/common/xfa_object.h"

CXFA_Node* XFA_NodeMerge_CloneOrMergeContainer(
    CXFA_Document* pDocument,
    CXFA_Node* pFormParent,
    CXFA_Node* pTemplateNode,
    FX_BOOL bRecursive,
    CXFA_NodeArray* pSubformArray = NULL);
CXFA_Node* XFA_DataMerge_FindDataScope(CXFA_Node* pParentFormNode);
CXFA_Node* XFA_DataMerge_FindFormDOMInstance(CXFA_Document* pDocument,
                                             XFA_ELEMENT eClassID,
                                             FX_DWORD dwNameHash,
                                             CXFA_Node* pFormParent);

#endif  // XFA_SRC_FXFA_SRC_PARSER_XFA_DOCUMENT_DATAMERGER_IMP_H_
