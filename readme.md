# OAuth 2.0 Redirect URI Hijacking Simulation

## Overview

This project is a **console-based simulation** of the OAuth 2.0 authentication flow, focusing on a common security vulnerability known as **Redirect URI Hijacking**.

It demonstrates:

* How insecure OAuth implementations can be exploited
* How attackers intercept authorization codes
* How proper validation prevents such attacks

## OAuth 2.0 Flow

1. User requests login
2. Application redirects user to authorization server
3. User authenticates
4. Authorization server sends code via redirect URI
5. Application exchanges code for access token

If redirect URI is not validated, attackers can exploit this step.

## Vulnerability: Redirect URI Hijacking

In the vulnerable system:

* User enters a malicious redirect URI (e.g., `attacker.com`)
* System does not validate it
* Authorization code is sent to attacker
* Attacker gains unauthorized access

## Defense Mechanism

The secure system:

* Uses a **whitelist of trusted URIs**
* Validates user input before redirect
* Blocks unauthorized requests

This ensures:

* Authorization codes are sent only to legitimate applications
* Unauthorized access is prevented

## System Design

### 1. Vulnerable System

* No redirect URI validation
* Allows attack simulation

### 2. Secure System

* Implements whitelist validation
* Prevents unauthorized redirects

## Technologies Used

* C++
* Standard libraries (`iostream`, `string`, `cstdlib`, `ctime`)

## How to Run

### Step 1: Compile

```bash
g++ oauth_simulation.cpp -o oauth
```

### Step 2: Run

```bash
./oauth
```

---

## Menu Options

```
1. Vulnerable System (Attack Demo)
2. Secure System (Defense Demo)
3. Exit
```

## Limitations

* No real OAuth server integration
* No real network communication
* No HTTPS or encryption
* Simplified authentication process
