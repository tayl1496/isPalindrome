/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Implementation file for an object thrown on violation of
 *  precondition.
 *
 *  Adapted from page 250 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 26 Sep 2018
 *
 *  @version 7.0 */

#include <stdexcept>
#include <string>

#include "PrecondViolatedExcep.h"

PrecondViolatedExcep::PrecondViolatedExcep(const std::string& message)
  : std::logic_error(message) {
}
