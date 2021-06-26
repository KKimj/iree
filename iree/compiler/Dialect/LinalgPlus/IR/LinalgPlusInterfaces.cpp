// Copyright 2021 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "iree/compiler/Dialect/LinalgPlus/IR/LinalgPlusInterfaces.h"

namespace mlir {
namespace iree_compiler {
namespace linalg_plus {

OpOperandVector::operator SmallVector<Value>() {
  SmallVector<Value> result;
  result.reserve(this->size());
  llvm::transform(*this, std::back_inserter(result),
                  [](OpOperand *opOperand) { return opOperand->get(); });
  return result;
}

namespace detail {
LogicalResult verifyLinalgPlusOpInterface(Operation *op) { return success(); }
}  // namespace detail

#include "iree/compiler/Dialect/LinalgPlus/IR/LinalgPlusInterfaces.cpp.inc"  // IWYU pragma: export
}  // namespace linalg_plus
}  // namespace iree_compiler
}  // namespace mlir
