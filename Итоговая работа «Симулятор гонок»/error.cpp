#include "error.h"

Error::Error(std::string text) {
	this->textError = text;
};

std::string Error::getText() {
	return "������! " + this->textError;
};