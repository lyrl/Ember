/*
 * Copyright (c) 2016 Ember
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <wsscheduler/Scheduler.h>

namespace ember { namespace task { namespace ws {

Scheduler::Scheduler(std::size_t workers) : workers_(workers) {

}

void Scheduler::steal_work(std::size_t victim) {

}

void Scheduler::run_job(Task task) {
	task(this, NULL);
}

}}} // ws, task, ember