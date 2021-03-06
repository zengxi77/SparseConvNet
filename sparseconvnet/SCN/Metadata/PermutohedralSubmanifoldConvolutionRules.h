// Copyright 2016-present, Facebook, Inc.
// All rights reserved.
//
// This source code is licensed under the license found in the
// LICENSE file in the root directory of this source tree.

#ifndef PERMUTOHEDRALSUBMANIFOLDCONVOLUTIONRULES_H
#define PERMUTOHEDRALSUBMANIFOLDCONVOLUTIONRULES_H

// N=10
// import torch
// a=torch.zeros(N,N)
// for i in range(N):
//     for j in range(i):
//         dp=(a[i,:]*a[j,:]).sum()
//         a[i,j]=(0.5-dp)/a[j,j]
//         dp=(a[i,:]*a[i,:]).sum()
//         a[i,i]=(1-dp)**0.5
// ai=torch.inverse(a)
// r=1
// for dim in range(1,N+1):
//     c=torch.arange((2*r+1)**dim).long()[:,None].expand(-1,dim)
//     c=c/((2*r+1)**torch.arange(0,dim).long())
//     c%=2*r+1
//     c-=r
//     c=c.float()
// for x in c:
//     v=(x[:,None]*a[:dim,:dim]).sum(0)
//     m=(v*v).sum().item()
//     if m<=r**2+0.01:
//	  print(v)

std::vector<std::vector<std::vector<Int>>> permutohedralOffsets = {
    {},
    {{0}, {-1}, {1}},
    {{0, -1}, {1, -1}, {-1, 0}, {0, 0}, {1, 0}, {-1, 1}, {0, 1}},
    {{0, 0, 0},
     {0, 0, -1},
     {1, 0, -1},
     {0, 1, -1},
     {0, -1, 0},
     {1, -1, 0},
     {-1, 0, 0},
     {1, 0, 0},
     {-1, 1, 0},
     {0, 1, 0},
     {0, -1, 1},
     {-1, 0, 1},
     {0, 0, 1}},
    {{0, 0, 0, 0},  {0, 0, 0, -1}, {1, 0, 0, -1}, {0, 1, 0, -1}, {0, 0, 1, -1},
     {0, 0, -1, 0}, {1, 0, -1, 0}, {0, 1, -1, 0}, {0, -1, 0, 0}, {1, -1, 0, 0},
     {-1, 0, 0, 0}, {1, 0, 0, 0},  {-1, 1, 0, 0}, {0, 1, 0, 0},  {0, -1, 1, 0},
     {-1, 0, 1, 0}, {0, 0, 1, 0},  {0, 0, -1, 1}, {0, -1, 0, 1}, {-1, 0, 0, 1},
     {0, 0, 0, 1}},
    {{0, 0, 0, 0, 0},  {0, 0, 0, 0, -1}, {1, 0, 0, 0, -1}, {0, 1, 0, 0, -1},
     {0, 0, 1, 0, -1}, {0, 0, 0, 1, -1}, {0, 0, 0, -1, 0}, {1, 0, 0, -1, 0},
     {0, 1, 0, -1, 0}, {0, 0, 1, -1, 0}, {0, 0, -1, 0, 0}, {1, 0, -1, 0, 0},
     {0, 1, -1, 0, 0}, {0, -1, 0, 0, 0}, {1, -1, 0, 0, 0}, {-1, 0, 0, 0, 0},
     {1, 0, 0, 0, 0},  {-1, 1, 0, 0, 0}, {0, 1, 0, 0, 0},  {0, -1, 1, 0, 0},
     {-1, 0, 1, 0, 0}, {0, 0, 1, 0, 0},  {0, 0, -1, 1, 0}, {0, -1, 0, 1, 0},
     {-1, 0, 0, 1, 0}, {0, 0, 0, 1, 0},  {0, 0, 0, -1, 1}, {0, 0, -1, 0, 1},
     {0, -1, 0, 0, 1}, {-1, 0, 0, 0, 1}, {0, 0, 0, 0, 1}},
    {{0, 0, 0, 0, 0, 0},  {0, 0, 0, 0, 0, -1}, {1, 0, 0, 0, 0, -1},
     {0, 1, 0, 0, 0, -1}, {0, 0, 1, 0, 0, -1}, {0, 0, 0, 1, 0, -1},
     {0, 0, 0, 0, 1, -1}, {0, 0, 0, 0, -1, 0}, {1, 0, 0, 0, -1, 0},
     {0, 1, 0, 0, -1, 0}, {0, 0, 1, 0, -1, 0}, {0, 0, 0, 1, -1, 0},
     {0, 0, 0, -1, 0, 0}, {1, 0, 0, -1, 0, 0}, {0, 1, 0, -1, 0, 0},
     {0, 0, 1, -1, 0, 0}, {0, 0, -1, 0, 0, 0}, {1, 0, -1, 0, 0, 0},
     {0, 1, -1, 0, 0, 0}, {0, -1, 0, 0, 0, 0}, {1, -1, 0, 0, 0, 0},
     {-1, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0},  {-1, 1, 0, 0, 0, 0},
     {0, 1, 0, 0, 0, 0},  {0, -1, 1, 0, 0, 0}, {-1, 0, 1, 0, 0, 0},
     {0, 0, 1, 0, 0, 0},  {0, 0, -1, 1, 0, 0}, {0, -1, 0, 1, 0, 0},
     {-1, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 0, 0},  {0, 0, 0, -1, 1, 0},
     {0, 0, -1, 0, 1, 0}, {0, -1, 0, 0, 1, 0}, {-1, 0, 0, 0, 1, 0},
     {0, 0, 0, 0, 1, 0},  {0, 0, 0, 0, -1, 1}, {0, 0, 0, -1, 0, 1},
     {0, 0, -1, 0, 0, 1}, {0, -1, 0, 0, 0, 1}, {-1, 0, 0, 0, 0, 1},
     {0, 0, 0, 0, 0, 1}},
    {{0, 0, 0, 0, 0, 0, 0},  {0, 0, 0, 0, 0, 0, -1}, {1, 0, 0, 0, 0, 0, -1},
     {0, 1, 0, 0, 0, 0, -1}, {0, 0, 1, 0, 0, 0, -1}, {0, 0, 0, 1, 0, 0, -1},
     {0, 0, 0, 0, 1, 0, -1}, {0, 0, 0, 0, 0, 1, -1}, {0, 0, 0, 0, 0, -1, 0},
     {1, 0, 0, 0, 0, -1, 0}, {0, 1, 0, 0, 0, -1, 0}, {0, 0, 1, 0, 0, -1, 0},
     {0, 0, 0, 1, 0, -1, 0}, {0, 0, 0, 0, 1, -1, 0}, {0, 0, 0, 0, -1, 0, 0},
     {1, 0, 0, 0, -1, 0, 0}, {0, 1, 0, 0, -1, 0, 0}, {0, 0, 1, 0, -1, 0, 0},
     {0, 0, 0, 1, -1, 0, 0}, {0, 0, 0, -1, 0, 0, 0}, {1, 0, 0, -1, 0, 0, 0},
     {0, 1, 0, -1, 0, 0, 0}, {0, 0, 1, -1, 0, 0, 0}, {0, 0, -1, 0, 0, 0, 0},
     {1, 0, -1, 0, 0, 0, 0}, {0, 1, -1, 0, 0, 0, 0}, {0, -1, 0, 0, 0, 0, 0},
     {1, -1, 0, 0, 0, 0, 0}, {-1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0},
     {-1, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0},  {0, -1, 1, 0, 0, 0, 0},
     {-1, 0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0},  {0, 0, -1, 1, 0, 0, 0},
     {0, -1, 0, 1, 0, 0, 0}, {-1, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0},
     {0, 0, 0, -1, 1, 0, 0}, {0, 0, -1, 0, 1, 0, 0}, {0, -1, 0, 0, 1, 0, 0},
     {-1, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0},  {0, 0, 0, 0, -1, 1, 0},
     {0, 0, 0, -1, 0, 1, 0}, {0, 0, -1, 0, 0, 1, 0}, {0, -1, 0, 0, 0, 1, 0},
     {-1, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 1, 0},  {0, 0, 0, 0, 0, -1, 1},
     {0, 0, 0, 0, -1, 0, 1}, {0, 0, 0, -1, 0, 0, 1}, {0, 0, -1, 0, 0, 0, 1},
     {0, -1, 0, 0, 0, 0, 1}, {-1, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 1}},
    {{0, 0, 0, 0, 0, 0, 0, 0},  {0, 0, 0, 0, 0, 0, 0, -1},
     {1, 0, 0, 0, 0, 0, 0, -1}, {0, 1, 0, 0, 0, 0, 0, -1},
     {0, 0, 1, 0, 0, 0, 0, -1}, {0, 0, 0, 1, 0, 0, 0, -1},
     {0, 0, 0, 0, 1, 0, 0, -1}, {0, 0, 0, 0, 0, 1, 0, -1},
     {0, 0, 0, 0, 0, 0, 1, -1}, {0, 0, 0, 0, 0, 0, -1, 0},
     {1, 0, 0, 0, 0, 0, -1, 0}, {0, 1, 0, 0, 0, 0, -1, 0},
     {0, 0, 1, 0, 0, 0, -1, 0}, {0, 0, 0, 1, 0, 0, -1, 0},
     {0, 0, 0, 0, 1, 0, -1, 0}, {0, 0, 0, 0, 0, 1, -1, 0},
     {0, 0, 0, 0, 0, -1, 0, 0}, {1, 0, 0, 0, 0, -1, 0, 0},
     {0, 1, 0, 0, 0, -1, 0, 0}, {0, 0, 1, 0, 0, -1, 0, 0},
     {0, 0, 0, 1, 0, -1, 0, 0}, {0, 0, 0, 0, 1, -1, 0, 0},
     {0, 0, 0, 0, -1, 0, 0, 0}, {1, 0, 0, 0, -1, 0, 0, 0},
     {0, 1, 0, 0, -1, 0, 0, 0}, {0, 0, 1, 0, -1, 0, 0, 0},
     {0, 0, 0, 1, -1, 0, 0, 0}, {0, 0, 0, -1, 0, 0, 0, 0},
     {1, 0, 0, -1, 0, 0, 0, 0}, {0, 1, 0, -1, 0, 0, 0, 0},
     {0, 0, 1, -1, 0, 0, 0, 0}, {0, 0, -1, 0, 0, 0, 0, 0},
     {1, 0, -1, 0, 0, 0, 0, 0}, {0, 1, -1, 0, 0, 0, 0, 0},
     {0, -1, 0, 0, 0, 0, 0, 0}, {1, -1, 0, 0, 0, 0, 0, 0},
     {-1, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0},
     {-1, 1, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0},
     {0, -1, 1, 0, 0, 0, 0, 0}, {-1, 0, 1, 0, 0, 0, 0, 0},
     {0, 0, 1, 0, 0, 0, 0, 0},  {0, 0, -1, 1, 0, 0, 0, 0},
     {0, -1, 0, 1, 0, 0, 0, 0}, {-1, 0, 0, 1, 0, 0, 0, 0},
     {0, 0, 0, 1, 0, 0, 0, 0},  {0, 0, 0, -1, 1, 0, 0, 0},
     {0, 0, -1, 0, 1, 0, 0, 0}, {0, -1, 0, 0, 1, 0, 0, 0},
     {-1, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0},
     {0, 0, 0, 0, -1, 1, 0, 0}, {0, 0, 0, -1, 0, 1, 0, 0},
     {0, 0, -1, 0, 0, 1, 0, 0}, {0, -1, 0, 0, 0, 1, 0, 0},
     {-1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0},
     {0, 0, 0, 0, 0, -1, 1, 0}, {0, 0, 0, 0, -1, 0, 1, 0},
     {0, 0, 0, -1, 0, 0, 1, 0}, {0, 0, -1, 0, 0, 0, 1, 0},
     {0, -1, 0, 0, 0, 0, 1, 0}, {-1, 0, 0, 0, 0, 0, 1, 0},
     {0, 0, 0, 0, 0, 0, 1, 0},  {0, 0, 0, 0, 0, 0, -1, 1},
     {0, 0, 0, 0, 0, -1, 0, 1}, {0, 0, 0, 0, -1, 0, 0, 1},
     {0, 0, 0, -1, 0, 0, 0, 1}, {0, 0, -1, 0, 0, 0, 0, 1},
     {0, -1, 0, 0, 0, 0, 0, 1}, {-1, 0, 0, 0, 0, 0, 0, 1},
     {0, 0, 0, 0, 0, 0, 0, 1}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0},  {0, 0, 0, 0, 0, 0, 0, 0, -1},
     {1, 0, 0, 0, 0, 0, 0, 0, -1}, {0, 1, 0, 0, 0, 0, 0, 0, -1},
     {0, 0, 1, 0, 0, 0, 0, 0, -1}, {0, 0, 0, 1, 0, 0, 0, 0, -1},
     {0, 0, 0, 0, 1, 0, 0, 0, -1}, {0, 0, 0, 0, 0, 1, 0, 0, -1},
     {0, 0, 0, 0, 0, 0, 1, 0, -1}, {0, 0, 0, 0, 0, 0, 0, 1, -1},
     {0, 0, 0, 0, 0, 0, 0, -1, 0}, {1, 0, 0, 0, 0, 0, 0, -1, 0},
     {0, 1, 0, 0, 0, 0, 0, -1, 0}, {0, 0, 1, 0, 0, 0, 0, -1, 0},
     {0, 0, 0, 1, 0, 0, 0, -1, 0}, {0, 0, 0, 0, 1, 0, 0, -1, 0},
     {0, 0, 0, 0, 0, 1, 0, -1, 0}, {0, 0, 0, 0, 0, 0, 1, -1, 0},
     {0, 0, 0, 0, 0, 0, -1, 0, 0}, {1, 0, 0, 0, 0, 0, -1, 0, 0},
     {0, 1, 0, 0, 0, 0, -1, 0, 0}, {0, 0, 1, 0, 0, 0, -1, 0, 0},
     {0, 0, 0, 1, 0, 0, -1, 0, 0}, {0, 0, 0, 0, 1, 0, -1, 0, 0},
     {0, 0, 0, 0, 0, 1, -1, 0, 0}, {0, 0, 0, 0, 0, -1, 0, 0, 0},
     {1, 0, 0, 0, 0, -1, 0, 0, 0}, {0, 1, 0, 0, 0, -1, 0, 0, 0},
     {0, 0, 1, 0, 0, -1, 0, 0, 0}, {0, 0, 0, 1, 0, -1, 0, 0, 0},
     {0, 0, 0, 0, 1, -1, 0, 0, 0}, {0, 0, 0, 0, -1, 0, 0, 0, 0},
     {1, 0, 0, 0, -1, 0, 0, 0, 0}, {0, 1, 0, 0, -1, 0, 0, 0, 0},
     {0, 0, 1, 0, -1, 0, 0, 0, 0}, {0, 0, 0, 1, -1, 0, 0, 0, 0},
     {0, 0, 0, -1, 0, 0, 0, 0, 0}, {1, 0, 0, -1, 0, 0, 0, 0, 0},
     {0, 1, 0, -1, 0, 0, 0, 0, 0}, {0, 0, 1, -1, 0, 0, 0, 0, 0},
     {0, 0, -1, 0, 0, 0, 0, 0, 0}, {1, 0, -1, 0, 0, 0, 0, 0, 0},
     {0, 1, -1, 0, 0, 0, 0, 0, 0}, {0, -1, 0, 0, 0, 0, 0, 0, 0},
     {1, -1, 0, 0, 0, 0, 0, 0, 0}, {-1, 0, 0, 0, 0, 0, 0, 0, 0},
     {1, 0, 0, 0, 0, 0, 0, 0, 0},  {-1, 1, 0, 0, 0, 0, 0, 0, 0},
     {0, 1, 0, 0, 0, 0, 0, 0, 0},  {0, -1, 1, 0, 0, 0, 0, 0, 0},
     {-1, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0},
     {0, 0, -1, 1, 0, 0, 0, 0, 0}, {0, -1, 0, 1, 0, 0, 0, 0, 0},
     {-1, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0},
     {0, 0, 0, -1, 1, 0, 0, 0, 0}, {0, 0, -1, 0, 1, 0, 0, 0, 0},
     {0, -1, 0, 0, 1, 0, 0, 0, 0}, {-1, 0, 0, 0, 1, 0, 0, 0, 0},
     {0, 0, 0, 0, 1, 0, 0, 0, 0},  {0, 0, 0, 0, -1, 1, 0, 0, 0},
     {0, 0, 0, -1, 0, 1, 0, 0, 0}, {0, 0, -1, 0, 0, 1, 0, 0, 0},
     {0, -1, 0, 0, 0, 1, 0, 0, 0}, {-1, 0, 0, 0, 0, 1, 0, 0, 0},
     {0, 0, 0, 0, 0, 1, 0, 0, 0},  {0, 0, 0, 0, 0, -1, 1, 0, 0},
     {0, 0, 0, 0, -1, 0, 1, 0, 0}, {0, 0, 0, -1, 0, 0, 1, 0, 0},
     {0, 0, -1, 0, 0, 0, 1, 0, 0}, {0, -1, 0, 0, 0, 0, 1, 0, 0},
     {-1, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0},
     {0, 0, 0, 0, 0, 0, -1, 1, 0}, {0, 0, 0, 0, 0, -1, 0, 1, 0},
     {0, 0, 0, 0, -1, 0, 0, 1, 0}, {0, 0, 0, -1, 0, 0, 0, 1, 0},
     {0, 0, -1, 0, 0, 0, 0, 1, 0}, {0, -1, 0, 0, 0, 0, 0, 1, 0},
     {-1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0},
     {0, 0, 0, 0, 0, 0, 0, -1, 1}, {0, 0, 0, 0, 0, 0, -1, 0, 1},
     {0, 0, 0, 0, 0, -1, 0, 0, 1}, {0, 0, 0, 0, -1, 0, 0, 0, 1},
     {0, 0, 0, -1, 0, 0, 0, 0, 1}, {0, 0, -1, 0, 0, 0, 0, 0, 1},
     {0, -1, 0, 0, 0, 0, 0, 0, 1}, {-1, 0, 0, 0, 0, 0, 0, 0, 1},
     {0, 0, 0, 0, 0, 0, 0, 0, 1}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  {0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
     {1, 0, 0, 0, 0, 0, 0, 0, 0, -1}, {0, 1, 0, 0, 0, 0, 0, 0, 0, -1},
     {0, 0, 1, 0, 0, 0, 0, 0, 0, -1}, {0, 0, 0, 1, 0, 0, 0, 0, 0, -1},
     {0, 0, 0, 0, 1, 0, 0, 0, 0, -1}, {0, 0, 0, 0, 0, 1, 0, 0, 0, -1},
     {0, 0, 0, 0, 0, 0, 1, 0, 0, -1}, {0, 0, 0, 0, 0, 0, 0, 1, 0, -1},
     {0, 0, 0, 0, 0, 0, 0, 0, 1, -1}, {0, 0, 0, 0, 0, 0, 0, 0, -1, 0},
     {1, 0, 0, 0, 0, 0, 0, 0, -1, 0}, {0, 1, 0, 0, 0, 0, 0, 0, -1, 0},
     {0, 0, 1, 0, 0, 0, 0, 0, -1, 0}, {0, 0, 0, 1, 0, 0, 0, 0, -1, 0},
     {0, 0, 0, 0, 1, 0, 0, 0, -1, 0}, {0, 0, 0, 0, 0, 1, 0, 0, -1, 0},
     {0, 0, 0, 0, 0, 0, 1, 0, -1, 0}, {0, 0, 0, 0, 0, 0, 0, 1, -1, 0},
     {0, 0, 0, 0, 0, 0, 0, -1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, -1, 0, 0},
     {0, 1, 0, 0, 0, 0, 0, -1, 0, 0}, {0, 0, 1, 0, 0, 0, 0, -1, 0, 0},
     {0, 0, 0, 1, 0, 0, 0, -1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, -1, 0, 0},
     {0, 0, 0, 0, 0, 1, 0, -1, 0, 0}, {0, 0, 0, 0, 0, 0, 1, -1, 0, 0},
     {0, 0, 0, 0, 0, 0, -1, 0, 0, 0}, {1, 0, 0, 0, 0, 0, -1, 0, 0, 0},
     {0, 1, 0, 0, 0, 0, -1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, -1, 0, 0, 0},
     {0, 0, 0, 1, 0, 0, -1, 0, 0, 0}, {0, 0, 0, 0, 1, 0, -1, 0, 0, 0},
     {0, 0, 0, 0, 0, 1, -1, 0, 0, 0}, {0, 0, 0, 0, 0, -1, 0, 0, 0, 0},
     {1, 0, 0, 0, 0, -1, 0, 0, 0, 0}, {0, 1, 0, 0, 0, -1, 0, 0, 0, 0},
     {0, 0, 1, 0, 0, -1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, -1, 0, 0, 0, 0},
     {0, 0, 0, 0, 1, -1, 0, 0, 0, 0}, {0, 0, 0, 0, -1, 0, 0, 0, 0, 0},
     {1, 0, 0, 0, -1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, -1, 0, 0, 0, 0, 0},
     {0, 0, 1, 0, -1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, -1, 0, 0, 0, 0, 0},
     {0, 0, 0, -1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, -1, 0, 0, 0, 0, 0, 0},
     {0, 1, 0, -1, 0, 0, 0, 0, 0, 0}, {0, 0, 1, -1, 0, 0, 0, 0, 0, 0},
     {0, 0, -1, 0, 0, 0, 0, 0, 0, 0}, {1, 0, -1, 0, 0, 0, 0, 0, 0, 0},
     {0, 1, -1, 0, 0, 0, 0, 0, 0, 0}, {0, -1, 0, 0, 0, 0, 0, 0, 0, 0},
     {1, -1, 0, 0, 0, 0, 0, 0, 0, 0}, {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},  {-1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},  {0, -1, 1, 0, 0, 0, 0, 0, 0, 0},
     {-1, 0, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, -1, 1, 0, 0, 0, 0, 0, 0}, {0, -1, 0, 1, 0, 0, 0, 0, 0, 0},
     {-1, 0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, -1, 1, 0, 0, 0, 0, 0}, {0, 0, -1, 0, 1, 0, 0, 0, 0, 0},
     {0, -1, 0, 0, 1, 0, 0, 0, 0, 0}, {-1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},  {0, 0, 0, 0, -1, 1, 0, 0, 0, 0},
     {0, 0, 0, -1, 0, 1, 0, 0, 0, 0}, {0, 0, -1, 0, 0, 1, 0, 0, 0, 0},
     {0, -1, 0, 0, 0, 1, 0, 0, 0, 0}, {-1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},  {0, 0, 0, 0, 0, -1, 1, 0, 0, 0},
     {0, 0, 0, 0, -1, 0, 1, 0, 0, 0}, {0, 0, 0, -1, 0, 0, 1, 0, 0, 0},
     {0, 0, -1, 0, 0, 0, 1, 0, 0, 0}, {0, -1, 0, 0, 0, 0, 1, 0, 0, 0},
     {-1, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, -1, 1, 0, 0}, {0, 0, 0, 0, 0, -1, 0, 1, 0, 0},
     {0, 0, 0, 0, -1, 0, 0, 1, 0, 0}, {0, 0, 0, -1, 0, 0, 0, 1, 0, 0},
     {0, 0, -1, 0, 0, 0, 0, 1, 0, 0}, {0, -1, 0, 0, 0, 0, 0, 1, 0, 0},
     {-1, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, -1, 1, 0}, {0, 0, 0, 0, 0, 0, -1, 0, 1, 0},
     {0, 0, 0, 0, 0, -1, 0, 0, 1, 0}, {0, 0, 0, 0, -1, 0, 0, 0, 1, 0},
     {0, 0, 0, -1, 0, 0, 0, 0, 1, 0}, {0, 0, -1, 0, 0, 0, 0, 0, 1, 0},
     {0, -1, 0, 0, 0, 0, 0, 0, 1, 0}, {-1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},  {0, 0, 0, 0, 0, 0, 0, 0, -1, 1},
     {0, 0, 0, 0, 0, 0, 0, -1, 0, 1}, {0, 0, 0, 0, 0, 0, -1, 0, 0, 1},
     {0, 0, 0, 0, 0, -1, 0, 0, 0, 1}, {0, 0, 0, 0, -1, 0, 0, 0, 0, 1},
     {0, 0, 0, -1, 0, 0, 0, 0, 0, 1}, {0, 0, -1, 0, 0, 0, 0, 0, 0, 1},
     {0, -1, 0, 0, 0, 0, 0, 0, 0, 1}, {-1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}}};

template <Int dimension> class PermutohedralRegionIterator;
template <Int dimension> class PermutohedralRegion {
public:
  Point<dimension> x;
  PermutohedralRegion(const Point<dimension> &x) : x(x) {
    assert(dimension <= 10);
  }
  PermutohedralRegionIterator<dimension> begin() {
    return PermutohedralRegionIterator<dimension>(*this, x);
  }
  PermutohedralRegionIterator<dimension> end() {
    // Not really used by the custom operator!= function
    return PermutohedralRegionIterator<dimension>(*this, x);
  }
};

template <Int dimension> class PermutohedralRegionIterator {
private:
  PermutohedralRegion<dimension> &region;
  unsigned int offset;

public:
  Point<dimension> point;
  bool stillLooping;
  PermutohedralRegionIterator(PermutohedralRegion<dimension> &region,
                              Point<dimension> &point)
      : region(region), offset(0), point(point), stillLooping(true) {}
  PermutohedralRegionIterator<dimension> &operator++() {
    auto offsets = permutohedralOffsets[dimension];
    if (++offset == offsets.size()) {
      stillLooping = false; // Signal to operator!= to end iteration
    } else {
      auto delta = offsets[offset];
      for (Int i = 0; i < dimension; ++i)
        point[i] = region.x[i] + delta[i];
    }
    return *this;
  }
  Point<dimension> &operator*() { return point; }
};

// Only to be used for checking the end point of range based for loops.
template <Int dimension>
inline bool operator!=(const PermutohedralRegionIterator<dimension> &lhs,
                       const PermutohedralRegionIterator<dimension> &rhs) {
  return lhs.stillLooping;
}

// Call for each convolutional layer, once for each batch item.
// rules is used to carry out the "lowering" whilst carrying out the convolution

template <Int dimension>
double
PermutohedralSubmanifoldConvolution_SgToRules(SparseGrid<dimension> &grid,
                                              RuleBook &rules) {
  double countActiveInputs = 0;
  for (auto const &outputIter : grid.mp) {
    auto inRegion = PermutohedralRegion<dimension>(outputIter.first);
    Int rulesOffset = 0;
    for (auto inputPoint : inRegion) {
      auto inputIter = grid.mp.find(inputPoint);
      if (inputIter != grid.mp.end()) {
        rules[rulesOffset].push_back(inputIter->second + grid.ctr);
        rules[rulesOffset].push_back(outputIter.second + grid.ctr);
        countActiveInputs++;
      }
      rulesOffset++;
    }
  }
  return countActiveInputs;
}

template <Int dimension>
Int PermutohedralSubmanifoldConvolution_SgsToRules(SparseGrids<dimension> &SGs,
                                                   RuleBook &rules) {
  Int sd = permutohedralOffsets[dimension].size();
  Int countActiveInputs = 0;
  rules.clear();
  rules.resize(sd);
  for (Int i = 0; i < (Int)SGs.size(); i++)
    countActiveInputs +=
        PermutohedralSubmanifoldConvolution_SgToRules<dimension>(SGs[i], rules);
  return countActiveInputs;
}
template <Int dimension>
Int PermutohedralSubmanifoldConvolution_SgsToRules_OMP(
    SparseGrids<dimension> &SGs, RuleBook &rules) {
  std::vector<RuleBook> rbs(SGs.size());
  std::vector<double> countActiveInputs(SGs.size());
  rules.clear();
  Int sd = permutohedralOffsets[dimension].size();
  rules.resize(sd);
  {
    Int i;
#pragma omp parallel for private(i)
    for (i = 0; i < (Int)SGs.size(); i++) {
      rbs[i].resize(sd);
      countActiveInputs[i] =
          PermutohedralSubmanifoldConvolution_SgToRules<dimension>(SGs[i],
                                                                   rbs[i]);
    }
  }
  {
    Int i;
#pragma omp parallel for private(i)
    for (i = 0; i < sd; i++)
      for (auto const &rb : rbs)
        rules[i].insert(rules[i].end(), rb[i].begin(), rb[i].end());
  }
  Int countActiveInputs_ = 0;
  for (auto &i : countActiveInputs)
    countActiveInputs_ += i;
  return countActiveInputs_;
}

#endif /* PERMUTOHEDRALSUBMANIFOLDCONVOLUTIONRULES_H */
