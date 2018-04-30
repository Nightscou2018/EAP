---
title: PumpCommunication
author: Rick van Schijndel
---

# Abstract

This document describes the responsibilities
of the pump communication component and classes
within.

## Responsibilities

The pump communication component is responsible for handling the connection
to the pump and to the pump and sending and receiving packets to it.

It makes sure packets to send and received are checked for validity,
before someone else can do something with them.

## Radio

The radio abstracts communication with the radio.

## Packet

The packet class is responsible for keeping track of a packet
and doing validation on the packet.


