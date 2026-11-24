// Original Porsche.exe SHA-256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39
// Run830: bindings and verified export table for existing canonical network RTTI locators:
//   005c5190 (20B) porsche::network_rtti_005c5190 (CConClient)
//   005c51d8 (20B) porsche::network_rtti_005c51d8 (CConnection)
//   005c5228 (20B) porsche::network_rtti_005c5228 (CConHost)
#pragma once

#include "porsche/rtti.hpp"

namespace porsche {

// Ordered canonical CompleteObjectLocator targets matching network_vtables.cpp slots
// 005b4968 (CConClient), 005b4970 (CConnection), 005b4978 (CConHost).
// bindings.cmake aliases ?network_rtti_005c5190/d8/28@porsche@@3QBEB to rtti.cpp's
// typed RttiCompleteObjectLocator definitions.
extern const RttiCompleteObjectLocator* const network_rtti_binding_targets_830[3];

} // namespace porsche
