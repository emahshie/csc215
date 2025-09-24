- Core memory: used until the 70s, can retain contents with power off, took programming error to wipe contents
- Bootstrap loader: minimum loader that allowed system to pull itself up into memory
- Firmware: software made harder by being burned into read only memory (ROM)

# Firmware Monitor
- Bootup circuit: activated by the same reset signal that starts the CPU, makes the RAM at location zero disappear and substitutes a shadow PROM containing instructions & reinstates RAM once it is done
- Turning power on and pressing the reset switch will get the machine running
- Monitor programs: use the console to communicate with the operator, and provide routines that enable him to interact intimately with the computer hardware, as is necessary for diagnosing hardware failures and debugging assembly language programs

# The Operating System
- I/O port assignments have not been standardized
- CP/M can be called upon to keep track of all the details required in disk accesses, as well as operations through I/O ports

# Customizing CP/M
- All disk and I/O accesses are passed through a single entry point into CP/M. To implement this, function codes are passed in one register, and the data or buffer address passed in other registers. Using these conventions, it is possible to write programs that will run on any computer hardware without modification

# Application Programs
- The RAM not used by the firmware monitor and resident portion of CP/M is available for user programs
- CP/M Loads and executes user programs in the transient program area (TPA)
- User programs/non-system software are referred to as application programs
- You use CP/M's editor (ED), assembler (ASM), loader (LOAD), and debugger (DDT) for application programs
- DDT has to be loaded along with application programs only until the programs are fully operational

# Special Memory Areas
- The lowest addresses of RAM are dedicated to vectors (unconditional jump instructions)
- Programs should not disturb these memory areas
- There are buffer areas above the vector spaces
- Different computers allocate different amounts of RAM to monitor functions
- Operating systems must not attempt to use any RAM space required by the monitor or other computer-specific functions, so sometimes a machine runs 46K saving the extra 2K for required functions
