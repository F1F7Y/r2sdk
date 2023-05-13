#pragma once

void SDK_Init();
void SDK_Shutdown();

void Systems_PreInit();
void Systems_Init();
void Systems_Shutdown();

void Winsock_Init();
void Winsock_Shutdown();
void QuerySystemInfo();
void CheckCPU();

void DetourInit();
void DetourAddress();
void DetourRegister();