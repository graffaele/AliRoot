#ifndef ALIPHOSRECPOINT_H
#define ALIPHOSRECPOINT_H
/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

////////////////////////////////////////////////
//  Base class for Reconstructed Points       //
//  in PHOS and PPSD                          //
//                                            //
//  Author Gines MARTINEZ    SUBATECH         //
//                                            //  
//                                            //
////////////////////////////////////////////////

// --- ROOT system ---

#include "TMarker.h"
#include "TGraph.h"
#include "TPaveText.h"

// --- Standard library ---

#include <cassert>

// --- AliRoot header files ---

#include "AliRecPoint.h"


class AliPHOSRecPoint : public AliRecPoint {

public:

  AliPHOSRecPoint() ;                   // ctor         
  virtual ~AliPHOSRecPoint() ;          // dtor
  virtual  void   AddDigit(AliDigitNew & digit, Float_t Energy) = 0 ; 
  virtual Int_t  DistancetoPrimitive(Int_t px, Int_t py);
  virtual void   Draw(Option_t * option="") ;
  virtual void   ExecuteEvent(Int_t event, Int_t px, Int_t py) ;
  virtual Int_t  GetPHOSMod(void) ;
  virtual Bool_t IsEmc(void){return kTRUE ;} 
  virtual  void  Paint(Option_t * option="");
  virtual void   Print(Option_t * opt = "void") {} 

  virtual Int_t   Compare(TObject * obj) {  assert(0==1) ; }   
  virtual Bool_t  IsSortable() const { return kTRUE ; }  

protected:
  
  Int_t      fPHOSMod ;

  ClassDef(AliPHOSRecPoint,1)
 
};

#endif // AliPHOSRECPOINT_H
