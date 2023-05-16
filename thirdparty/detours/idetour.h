#ifndef IDETOUR_H
#define IDETOUR_H

#define ADDDETOUR(det,count,mod) static std::size_t dummy_reg_##count = AddDetour( #mod, new det() );
#define XREGISTER(det,count,mod) ADDDETOUR(det, count, mod)
#define REGISTER(mod,det)        XREGISTER(det, __COUNTER__, mod)

class IDetour
{
public:
	virtual ~IDetour() { ; }
	virtual void GetAdr(void) const = 0;
	virtual void GetFun(void) const = 0;
	virtual void GetVar(void) const = 0;
	virtual void GetCon(void) const = 0;

	virtual void Attach(void) const = 0;
	virtual void Detach(void) const = 0;
};

class VDetour : public IDetour
{
	virtual void GetAdr(void) const { }
	virtual void GetFun(void) const { }
	virtual void GetVar(void) const { }
	virtual void GetCon(void) const { }

	virtual void Attach(void) const { }
	virtual void Detach(void) const { }
};

inline static std::unordered_map<std::string, std::vector<IDetour*>> g_DetourMap;
inline static std::unordered_set<IDetour*> g_DetourSet;
inline std::size_t AddDetour(std::string strModule, IDetour* pDetour)
{
	IDetour* pVFTable = reinterpret_cast<IDetour**>(pDetour)[0];
	auto p = g_DetourSet.insert(pVFTable); // Only register if VFTable isn't already registered.

	assert(p.second); // Code bug: duplicate registration!!! (called 'REGISTER(...)' from a header file?).
	p.second ? g_DetourMap[strModule].push_back(pDetour) : delete pDetour;

	return g_DetourMap[strModule].size();
}

// [Fifty]: Registering this breaks func addr logging???
// TODO: Look into this, ask amos?
//REGISTER(VDetour);
#endif // IDETOUR_H
