// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef XFA_FXFA_PARSER_CXFA_FILL_H_
#define XFA_FXFA_PARSER_CXFA_FILL_H_

#include "core/fxcrt/fx_coordinates.h"
#include "core/fxge/fx_dib.h"
#include "xfa/fgas/graphics/cfgas_gepath.h"
#include "xfa/fxfa/parser/cxfa_node.h"

class CFGAS_GEGraphics;
class CXFA_Linear;
class CXFA_Pattern;
class CXFA_Radial;
class CXFA_Stipple;

class CXFA_Fill final : public CXFA_Node {
 public:
  CONSTRUCT_VIA_MAKE_GARBAGE_COLLECTED;
  ~CXFA_Fill() override;

  bool IsVisible();

  FX_ARGB GetColor(bool bText);
  void SetColor(FX_ARGB color);

  void Draw(CFGAS_GEGraphics* pGS,
            CFGAS_GEPath* fillPath,
            const CFX_RectF& rtWidget,
            const CFX_Matrix& matrix);

 private:
  CXFA_Fill(CXFA_Document* doc, XFA_PacketType packet);

  XFA_Element GetType() const;

  void DrawStipple(CFGAS_GEGraphics* pGS,
                   CFGAS_GEPath* fillPath,
                   const CFX_RectF& rtWidget,
                   const CFX_Matrix& matrix);
  void DrawRadial(CFGAS_GEGraphics* pGS,
                  CFGAS_GEPath* fillPath,
                  const CFX_RectF& rtWidget,
                  const CFX_Matrix& matrix);
  void DrawLinear(CFGAS_GEGraphics* pGS,
                  CFGAS_GEPath* fillPath,
                  const CFX_RectF& rtWidget,
                  const CFX_Matrix& matrix);
  void DrawPattern(CFGAS_GEGraphics* pGS,
                   CFGAS_GEPath* fillPath,
                   const CFX_RectF& rtWidget,
                   const CFX_Matrix& matrix);
};

#endif  // XFA_FXFA_PARSER_CXFA_FILL_H_
