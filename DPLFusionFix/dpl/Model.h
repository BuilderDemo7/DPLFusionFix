#pragma once
struct IRuntimeModelModule__vtable {
	int IRuntimeModelModule;
	int Initialise;
	int GetVertexPointer;
	int UpdateModel;
	int DrawModel;
	int DrawLitModel;
	int SetDrawInterface;
};

struct IRuntimeModelModule {
	struct IRuntimeModelModule__vtable *__vtable; // Inherited from IInterface
};