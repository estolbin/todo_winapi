#include <string>
#include "Tasks.h"

 Tasks::Tasks(int id, const std::string& description,
        const time_t& created,
        const time_t& deadline)
      : id(id), description(description), created(created), deadline(deadline)
      {
        isDone = false;
      }

  int Tasks::getId() const { return id; }
  const std::string& Tasks::getDescription() const { return description; }
  const time_t& Tasks::getCreated() const { return created; }
  const time_t& Tasks::getDeadline() const { return deadline; }
  bool Tasks::getIsDone() const {return isDone;}

  void Tasks::setIsDone() {this->isDone = !this->isDone;}





