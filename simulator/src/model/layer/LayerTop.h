/*******************************************************************************
 * Copyright (C) 2018 Jan Moritz Joseph
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/
#ifndef SRC_LAYERTOP_H_
#define SRC_LAYERTOP_H_

#include <iostream>
#include <map>
#include <string>

#include "systemc.h"

#include "../../traffic/Flit.h"
#include "../../utils/Structures.h"
#include "../../utils/GlobalInputClass.h"
#include "../../utils/Report.h"

#include "../processingElements/ProcessingElementVC3D.h"

#include "../container/Container.h"
#include "../container/ClassicContainer.h"

#include "../router/Router.h"
#include "../router/RouterVC.h"

#include "../link/Link.h"


class LayerTop: public sc_module {

private:
	GlobalInputClass &global = GlobalInputClass::getInstance();
	Report& rep = Report::getInstance();

	int dbid;
	std::vector<Router*> router;
	std::vector<SignalContainer*> signalContainer;
	std::vector<Link*> link;

public:
	SC_HAS_PROCESS(LayerTop);
	LayerTop(sc_module_name);


	std::vector<ProcessingElementVC3D*> processingElements;
};

#endif /* SRC_LAYERTOP_H_ */
