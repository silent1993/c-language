--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   23:33:20 07/03/2014
-- Design Name:   
-- Module Name:   D:/vhdl/lab_5/ctrl_tb.vhd
-- Project Name:  lab_5
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ctrl
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY ctrl_tb IS
END ctrl_tb;
 
ARCHITECTURE behavior OF ctrl_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ctrl
    PORT(
         d9 : IN  std_logic;
         d11 : IN  std_logic;
         sq7 : IN  std_logic;
         sq6 : IN  std_logic;
         rq : IN  std_logic_vector(7 downto 0);
         clrn : INOUT  std_logic;
         start : OUT  std_logic;
         serial : IN  std_logic;
         clk : IN  std_logic;
         csn : IN  std_logic;
         wrn : IN  std_logic;
         rdn : IN  std_logic;
         addr : IN  std_logic_vector(1 downto 0);
         data : INOUT  std_logic_vector(7 downto 0);
         intn : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal d9 : std_logic := '0';
   signal d11 : std_logic := '0';
   signal sq7 : std_logic := '0';
   signal sq6 : std_logic := '0';
   signal rq : std_logic_vector(7 downto 0) := (others => '0');
   signal serial : std_logic := '0';
   signal clk : std_logic := '0';
   signal csn : std_logic := '0';
   signal wrn : std_logic := '0';
   signal rdn : std_logic := '0';
   signal addr : std_logic_vector(1 downto 0) := (others => '0');

	--BiDirs
   signal clrn : std_logic;
   signal data : std_logic_vector(7 downto 0);

 	--Outputs
   signal start : std_logic;
   signal intn : std_logic;

   -- Clock period definitions
   constant clk_period : time :=50 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ctrl PORT MAP (
          d9 => d9,
          d11 => d11,
          sq7 => sq7,
          sq6 => sq6,
          rq => rq,
          clrn => clrn,
          start => start,
          serial => serial,
          clk => clk,
          csn => csn,
          wrn => wrn,
          rdn => rdn,
          addr => addr,
          data => data,
          intn => intn
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- ho	ld reset state for 100 ns.
		wait for clk_period;
      d9 <='1';
		d11<='1';
		sq7 <='1';
			sq6<='1';
		rq <="10111011";
    rdn <='1';
	 wrn<='1';
	 addr<="00";
	 data<="ZZZZZZZZ";
		wait for clk_period;
		d9<='0';
		addr<="01";
		data<="ZZZZZZZZ";
		wait for clk_period;
		d9<='1';
		d11<='0';
		sq7 <='0';
		sq6<='0';
		addr<="10";
		data<="ZZZZZZZZ";
		wait for clk_period;
		
		wrn<='1';
		rdn<='1';
		addr<="11";
		
		wait for clk_period;
		d11<='1';
		serial<='1';
		wrn<='1';
		rdn<='1';
		addr<="11";
		data<="10111000";
		wait for clk_period;
			d11<='1';
		serial<='1';
		wrn<='1';
		rdn<='1';
		addr<="11";
		data<="10111000";
		wait for clk_period;
		d11<='1';
		sq7<='1';
		sq6<='1';
wait for clk_period;
		rdn<='0';
		addr<="00";
			data<="ZZZZZZZZ";
	
      wait;
   end process;

END;
