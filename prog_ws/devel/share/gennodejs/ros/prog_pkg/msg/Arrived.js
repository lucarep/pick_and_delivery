// Auto-generated. Do not edit!

// (in-package prog_pkg.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Arrived {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.reached_goal = null;
    }
    else {
      if (initObj.hasOwnProperty('reached_goal')) {
        this.reached_goal = initObj.reached_goal
      }
      else {
        this.reached_goal = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Arrived
    // Serialize message field [reached_goal]
    bufferOffset = _serializer.int64(obj.reached_goal, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Arrived
    let len;
    let data = new Arrived(null);
    // Deserialize message field [reached_goal]
    data.reached_goal = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'prog_pkg/Arrived';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e06eb18f4448ce87af267960da61e43d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 reached_goal
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Arrived(null);
    if (msg.reached_goal !== undefined) {
      resolved.reached_goal = msg.reached_goal;
    }
    else {
      resolved.reached_goal = 0
    }

    return resolved;
    }
};

module.exports = Arrived;
